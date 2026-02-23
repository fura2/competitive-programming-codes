#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class capa_t>
class mf_graph{
	struct edge{
		int to,rev;
		capa_t capa,flow;
		edge(int to,int rev,const capa_t& capa,const capa_t& flow):to(to),rev(rev),capa(capa),flow(flow){}
	};

	vector<vector<edge>> G;

public:
	mf_graph(){}
	mf_graph(int n):G(n){}

	void add_directed_edge(int u,int v,const capa_t& capa){
		G[u].emplace_back(v,G[v].size()  ,capa,0);
		G[v].emplace_back(u,G[u].size()-1,   0,0);
	}

	void add_undirected_edge(int u,int v,const capa_t& capa){
		G[u].emplace_back(v,G[v].size()  ,capa,0);
		G[v].emplace_back(u,G[u].size()-1,capa,0);
	}

	capa_t maximum_flow(int s,int t){
		int n=G.size();
		vector<int> pre(n);
		vector<bool> vis(n);

		auto augment=[&](){
			rep(u,n) vis[u]=(u==s);

			queue<pair<int,capa_t>> Q; Q.emplace(s,0);
			for(const edge& e:G[s]){
				Q.front().second=max(Q.front().second,e.capa-e.flow);
			}

			capa_t res=0;
			while(!Q.empty()){
				int u;
				capa_t water; tie(u,water)=Q.front(); Q.pop();

				if(u==t){ res=water; break; }

				for(const edge& e:G[u]) if(!vis[e.to] && e.capa-e.flow>0) {
					vis[e.to]=true;
					pre[e.to]=e.rev;
					Q.emplace(e.to,min(water,e.capa-e.flow));
				}
			}

			if(res>0){
				for(int u=t;u!=s;){
					edge& e1=G[u][pre[u]];
					edge& e2=G[e1.to][e1.rev];
					e1.flow-=res;
					e2.flow+=res;
					u=e1.to;
				}
			}

			return res;
		};

		capa_t res=0;
		for(capa_t water=1;water>0;res+=water) water=augment();
		return res;
	}
};

int main(){
	int n,m,p,k;
	scanf("%d%d%d%d",&m,&n,&p,&k);

	mf_graph<int> G(n+1);
	int s=n,t=0;
	rep(i,k){
		int u; scanf("%d",&u);
		G.add_directed_edge(s,u,p);
	}
	rep(i,m){
		int u,v,capa; scanf("%d%d%d",&u,&v,&capa);
		G.add_directed_edge(u,v,capa);
	}
	puts(G.maximum_flow(s,t)>=p?"Yes":"No");

	return 0;
}
