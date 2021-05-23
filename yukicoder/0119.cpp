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
};

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);

	/*
		(s, s) : ツアーなし
		(s, t) : 行かない
		(t, t) : ツアーあり
	*/
	mf_graph<int> G(2*n+2);
	int s=2*n,t=2*n+1;
	rep(i,n){
		G.add_directed_edge(n+i,i,INF); // (t, s) の可能性を排除
	}

	int sum=0;
	rep(i,n){
		int b,c; scanf("%d%d",&b,&c);
		int mx=max(b,c);
		sum+=mx;
		// 行かない場合, mx 円の罰金
		G.add_directed_edge(i,n+i,mx);
		// ツアーありの場合, mx-b 円の罰金
		G.add_directed_edge(s,i,mx-b);
		// ツアーなしの場合, mx-c 円の罰金
		G.add_directed_edge(n+i,t,mx-c);
	}
	int m; scanf("%d",&m);
	rep(i,m){
		int x,y; scanf("%d%d",&x,&y);
		// x がツアーあり => y はツアーあり or 行かない
		// すなわち, x がツアーあり and y がツアーなしの場合, ∞ 円の罰金
		G.add_directed_edge(n+y,x,INF);
	}

	printf("%d\n",sum-G.maximum_flow(s,t));

	return 0;
}
