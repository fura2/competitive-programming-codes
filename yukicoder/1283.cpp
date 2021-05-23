#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

template<class T>
void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
}

template<class T>
vector<T> Dijkstra(const weighted_graph<T>& G,int s){
	constexpr T INF=numeric_limits<T>::max();
	int n=G.size();
	vector<T> d(n,INF); d[s]=0;
	priority_queue<pair<T,int>> Q; Q.emplace(0,s);
	while(!Q.empty()){
		T d0=-Q.top().first;
		int u=Q.top().second; Q.pop();
		if(d0>d[u]) continue;
		for(const auto& e:G[u]){
			int v=e.to;
			if(d[v]>d[u]+e.wt){
				d[v]=d[u]+e.wt;
				Q.emplace(-d[v],v);
			}
		}
	}
	return d;
}

const long long INF=1LL<<61;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector cost(n,vector(n,0LL));
	rep(i,m){
		int x,y;
		lint c; scanf("%d%d%lld",&x,&y,&c); x--; y--;
		cost[x][y]=c;
	}

	weighted_graph<lint> G(n*n);
	rep(i,n) rep(j,n) rep(k,4) {
		int x=i+dx[k],y=j+dy[k];
		if(0<=x && x<n && 0<=y && y<n){
			add_directed_edge(G,i*n+j,x*n+y,cost[x][y]+1);
		}
	}

	auto d1=Dijkstra(G,0);
	auto d2=Dijkstra(G,n*n-1);

	lint ans=INF;
	rep(i,n) rep(j,n) ans=min(ans,d1[i*n+j]+d2[i*n+j]-2*cost[i][j]);
	printf("%lld\n",ans);

	return 0;
}
