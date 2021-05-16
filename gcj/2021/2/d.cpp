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

void solve(){
	int h,w,cf,cs; cin>>h>>w>>cf>>cs;
	vector B1(h,vector(w,0));
	vector B2(h,vector(w,0));
	rep(i,h){ string s; cin>>s; rep(j,w) B1[i][j]=(s[j]=='M'?0:1); }
	rep(i,h){ string s; cin>>s; rep(j,w) B2[i][j]=(s[j]=='M'?0:1); }

	int N=2*h*w+2;
	int s=N-2,t=N-1;
	mcf_graph<lint,lint> G(N);
	rep(i,h) rep(j,w) {
		G.add_directed_edge(s,i*w+j,1,0);
		G.add_directed_edge(h*w+i*w+j,t,1,0);
	}
	rep(i1,h) rep(j1,w) rep(i2,h) rep(j2,w) {
		if(B1[i1][j1]==0 && B2[i2][j2]==0) {
			G.add_directed_edge(i1*w+j1,h*w+i2*w+j2,1,0);
		}
		else if(B1[i1][j1]==1 && B2[i2][j2]==1){
			G.add_directed_edge(i1*w+j1,h*w+i2*w+j2,1,cs*(abs(i1-i2)+abs(j1-j2)));
		}
		else{
			G.add_directed_edge(i1*w+j1,h*w+i2*w+j2,1,cs*(abs(i1-i2)+abs(j1-j2))+cf);
		}
	}
	printf("%lld\n",G.minimum_cost_flow(s,t).second);
}

int main(){
	int t; scanf("%d",&t);
	rep(_,t){
		printf("Case #%d: ",_+1);
		solve();
	}
	return 0;
}
