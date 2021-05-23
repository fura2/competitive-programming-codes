#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

template<class T>
void add_undirected_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
	G[v].emplace_back(u,wt);
}

const int INF=1<<29;

int main(){
	int n,m,x; scanf("%d%d%d",&n,&m,&x);
	vector<int> T(n);
	rep(u,n) scanf("%d",&T[u]);
	weighted_graph<int> G(n);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		add_undirected_edge(G,u,v,c);
	}

	vector d(n,vector(2*x+1,INF));
	d[0][0]=0;
	priority_queue<pair<int,pair<int,int>>> Q; Q.emplace(0,make_pair(0,0));
	while(!Q.empty()){
		int d0=-Q.top().first,u,t;
		tie(u,t)=Q.top().second; Q.pop();
		if(d0>d[u][t]) continue;

		for(const auto& e:G[u]){
			int v=e.to,t2=-1;

			if(T[v]==0){
				if(t<=x){ // cold -> cold or good -> cold
					t2=0;
				}
				else if(t-x<=e.wt){ // hot -> cold
					t2=0;
				}
			}
			else if(T[v]==2){
				if(t>=x){ // hot -> hot or good -> hot
					t2=2*x;
				}
				else if(x-t<=e.wt){ // cold -> hot
					t2=2*x;
				}
			}
			else{ // T[v]==1
				if(t<=x){ // cold -> good or good -> good
					t2=min(t+e.wt,x);
				}
				else{ // hot -> good
					t2=max(t-e.wt,x);
				}
			}

			if(t2!=-1 && d[v][t2]>d[u][t]+e.wt){
				d[v][t2]=d[u][t]+e.wt;
				Q.emplace(-d[v][t2],make_pair(v,t2));
			}
		}
	}

	int ans=INF;
	rep(u,n) rep(t,2*x+1) ans=min(ans,d[n-1][t]);
	printf("%d\n",ans);

	return 0;
}
