#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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

		auto augment=[&](bool first)->pair<capa_t,cost_t>{
			rep(u,n) d[u]=(u==s?0:COST_INF);

			bool ok;
			if(first){
				// Bellman-Ford
				rep(_,n){
					bool upd=false;
					rep(u,n) if(d[u]<COST_INF) {
						for(const edge& e:G[u]) if(e.capa-e.flow>0) {
							if(d[e.to]>d[u]+e.cost){
								d[e.to]=d[u]+e.cost;
								pre[e.to]=e.rev;
								upd=true;
							}
						}
					}
					if(!upd) break;
				}
				ok=(d[t]<COST_INF);
			}
			else{
				// Dijkstra
				ok=false;
				Q.emplace(0,s);
				while(!Q.empty()){
					int u=Q.top().second;
					cost_t cost=-Q.top().first; Q.pop();

					if(cost<d[u]) continue;
					if(u==t) ok=true;

					for(const edge& e:G[u]) if(e.capa-e.flow>0) {
						cost_t cost2=cost+e.cost+pot[u]-pot[e.to];
						if(d[e.to]>cost2){
							d[e.to]=cost2;
							pre[e.to]=e.rev;
							Q.emplace(-cost2,e.to);
						}
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

			cost_t cost=0;
			for(int u=t;u!=s;){
				edge& e1=G[u][pre[u]];
				edge& e2=G[e1.to][e1.rev];
				e1.flow-=water;
				e2.flow+=water;
				cost+=water*e2.cost;
printf("  u = %d\n",u);
				u=e1.to;
			}

			rep(u,n) pot[u]+=d[u];
//printf("cost = %d, water = %d, pot[t] = %d\n",cost,water,pot[t]);
rep(u,n) printf("pot[%d] = %d\n",u,pot[u]);

			return {water,cost};
		};

		capa_t res1=0;
		cost_t res2=0;
		for(bool first=true;limit>0;first=false){
			auto tmp=augment(first);
			if(tmp.first==0) break;
			res1+=tmp.first;
			res2+=tmp.second;
		}
		return {res1,res2};
	}
};

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	mcf_graph<int,int> G(h*w+2);
	int s=h*w,t=h*w+1;

	rep(i,h) rep(j,w) {
		if(B[i][j]=='o'){
			G.add_directed_edge(s,i*w+j,1,0);
		}
		if(B[i][j]!='#'){
			G.add_directed_edge(i*w+j,t,1,0);
		}
		if(i<h-1 && B[i][j]!='#' && B[i+1][j]!='#'){
			G.add_directed_edge(i*w+j,(i+1)*w+j,h*w,-1);
		}
		if(j<w-1 && B[i][j]!='#' && B[i][j+1]!='#'){
			G.add_directed_edge(i*w+j,i*w+(j+1),h*w,-1);
		}
	}

	printf("%d\n",-G.minimum_cost_flow(s,t).second);

	return 0;
}
