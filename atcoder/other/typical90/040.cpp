#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class capa_t>
class mf_graph{
	struct edge{
		int to,rev;
		capa_t capa,flow;
		edge(int to,int rev,const capa_t& capa,const capa_t& flow):to(to),rev(rev),capa(capa),flow(flow){}
	};

	vector<vector<edge>> G;
	vector<int> layer,cur;

	bool make_layer(int s,int t){
		int n=G.size();
		rep(u,n) layer[u]=(u==s?0:-1);

		queue<int> Q; Q.emplace(s);
		while(!Q.empty()){
			int u=Q.front(); Q.pop();
			for(const edge& e:G[u]) if(layer[e.to]==-1 && e.capa-e.flow>0) {
				layer[e.to]=layer[u]+1;
				if(e.to==t) return true;
				Q.emplace(e.to);
			}
		}
		return false;
	}

	capa_t augment(int u,int t,const capa_t& water){
		if(u==t) return water;

		for(int& i=cur[u];i<G[u].size();i++){
			edge& e=G[u][i];
			if(layer[e.to]>layer[u] && e.capa-e.flow>0){
				capa_t w=augment(e.to,t,min(water,e.capa-e.flow));
				if(w>0){
					e.flow+=w;
					G[e.to][e.rev].flow-=w;
					return w;
				}
			}
		}
		return 0;
	}

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
		layer.resize(n);

		capa_t res=0;
		while(make_layer(s,t)){
			cur.assign(n,0);
			for(capa_t water=1;water>0;res+=water){
				water=augment(s,t,numeric_limits<capa_t>::max());
			}
		}
		return res;
	}

	vector<int> minimum_cut(int s){
		int n=G.size();
		vector<int> res;
		vector vis(n,false);
		vis[s]=true;
		queue<int> Q;
		Q.emplace(s);
		while(!Q.empty()){
			int u=Q.front(); Q.pop();
			res.emplace_back(u);
			for(const edge& e:G[u]) if(!vis[e.to] && e.capa-e.flow>0) {
				vis[e.to]=true;
				Q.emplace(e.to);
			}
		}
		return res;
	}
};

const long long INF=1LL<<61;

int main(){
	int n;
	lint w; scanf("%d%lld",&n,&w);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);
	vector to(n,vector<int>());
	rep(i,n){
		int k; scanf("%d",&k);
		to[i].resize(k);
		rep(j,k) scanf("%d",&to[i][j]), to[i][j]--;
	}

	int s=n,t=n+1;
	mf_graph<lint> G(n+2);
	rep(i,n){
		// 家 i に入るなら W 円の罰金
		G.add_directed_edge(i,t,w);
		// 家 i に入らないなら A_i 円の罰金
		G.add_directed_edge(s,i,a[i]);
		for(int j:to[i]){
			// 家 j に入って家 i に入らないなら +∞ 円の罰金
			G.add_directed_edge(j,i,INF);
		}
	}
	printf("%lld\n",accumulate(a.begin(),a.end(),0LL)-G.maximum_flow(s,t));

	return 0;
}
