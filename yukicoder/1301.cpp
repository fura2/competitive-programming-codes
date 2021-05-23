#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class capa_t,class cost_t>
class mcf_graph{
	struct edge{
		int to,rev;
		capa_t capa,flow;
		cost_t cost;
		edge(int to,int rev,const capa_t& capa,const cost_t& cost,const capa_t& flow):to(to),rev(rev),capa(capa),cost(cost),flow(flow){}
	};

	vector<vector<edge>> G;

	static constexpr capa_t CAPA_INF=numeric_limits<capa_t>::max();
	static constexpr cost_t COST_INF=numeric_limits<cost_t>::max();

public:
	mcf_graph(){}
	mcf_graph(int n):G(n){}

	void add_directed_edge(int u,int v,const capa_t& capa,const cost_t& cost){
		G[u].emplace_back(v,G[v].size()  ,capa, cost,0);
		G[v].emplace_back(u,G[u].size()-1,   0,-cost,0);
	}

	pair<capa_t,cost_t> minimum_cost_flow(int s,int t,capa_t limit=CAPA_INF){
		int n=G.size();
		vector<int> pre(n);
		vector<cost_t> d(n),pot(n);
		priority_queue<pair<cost_t,int>> Q;

		auto augment=[&]()->pair<capa_t,cost_t>{
			rep(u,n) d[u]=(u==s?0:COST_INF);

			// Dijkstra
			bool ok=false;
			Q.emplace(0,s);
			while(!Q.empty()){
				int u;
				cost_t tmp; tie(tmp,u)=Q.top(); Q.pop();

				if(-tmp<d[u]) continue;
				if(u==t) ok=true;

				for(const edge& e:G[u]) if(e.capa-e.flow>0) {
					cost_t cost2=d[u]+e.cost+pot[u]-pot[e.to];
					if(d[e.to]>cost2){
						d[e.to]=cost2;
						pre[e.to]=e.rev;
						Q.emplace(-cost2,e.to);
					}
				}
			}

			if(!ok) return {0,0};

			capa_t water=limit;
			for(int u=t;u!=s;){
				edge& e1=G[u][pre[u]];
				edge& e2=G[e1.to][e1.rev];
				water=min(water,e2.capa-e2.flow);
				u=e1.to;
			}
			limit-=water;

			for(int u=t;u!=s;){
				edge& e1=G[u][pre[u]];
				edge& e2=G[e1.to][e1.rev];
				e1.flow-=water;
				e2.flow+=water;
				u=e1.to;
			}

			rep(u,n) pot[u]+=d[u];

			return {water,water*pot[t]};
		};

		capa_t res1=0;
		cost_t res2=0;
		while(limit>0){
			auto tmp=augment();
			if(tmp.first==0) break;
			res1+=tmp.first;
			res2+=tmp.second;
		}
		return {res1,res2};
	}
};

int main(){
	int n,m; scanf("%d%d",&n,&m);

	mcf_graph<int,lint> G(n);
	rep(i,m){
		int u,v;
		lint c1,c2; scanf("%d%d%lld%lld",&u,&v,&c1,&c2); u--; v--;
		G.add_directed_edge(u,v,1,c1);
		G.add_directed_edge(u,v,1,c2);
		G.add_directed_edge(v,u,1,c1);
		G.add_directed_edge(v,u,1,c2);
	}

	printf("%lld\n",G.minimum_cost_flow(0,n-1,2).second);

	return 0;
}
