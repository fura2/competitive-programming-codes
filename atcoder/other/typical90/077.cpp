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
	vector<int> solve(int n){
		vector<int> res(n);
		rep(u,n){
			for(auto e:G[u]){
				int v=e.to;
				if(v>=n && e.flow==e.capa) res[u]=v;
			}
		}
		return res;
	}
};

const int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};

int main(){
	int n,T; scanf("%d%d",&n,&T);
	vector<int> x1(n),y1(n),x2(n),y2(n);
	rep(i,n) scanf("%d%d",&x1[i],&y1[i]);
	rep(i,n) scanf("%d%d",&x2[i],&y2[i]);

	map<pair<int,int>,int> f;
	rep(i,n) f[{x2[i],y2[i]}]=i;

	int N=2*n+2;
	int s=N-2,t=N-1;
	mf_graph<int> G(N);
	rep(i,n){
		G.add_directed_edge(s,i,1);
		G.add_directed_edge(n+i,t,1);
		rep(k,8){
			int xx=x1[i]+T*dx[k],yy=y1[i]+T*dy[k];
			if(f.count({xx,yy})>0){
				G.add_directed_edge(i,n+f[{xx,yy}],1);
			}
		}
	}

	if(G.maximum_flow(s,t)<n){
		puts("No");
		return 0;
	}

	puts("Yes");
	auto res=G.solve(n);
	rep(i,n){
		int j=res[i]-n;
		rep(k,8){
			int xx=x1[i]+T*dx[k],yy=y1[i]+T*dy[k];
			if(xx==x2[j] && yy==y2[j]){
				printf("%d%c",k+1,i<n-1?' ':'\n');
			}
		}
	}

	return 0;
}
