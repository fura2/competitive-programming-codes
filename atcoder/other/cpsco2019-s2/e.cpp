#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

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

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);
	weighted_graph<lint> T(n);
	for(int u=1;u<n;u++){
		int p;
		lint c; scanf("%d%lld",&p,&c);
		add_directed_edge(T,p,u,c);
	}

	// dp[u][k] = (u を頂点とする部分木において, k 本の辺を切断するための最小コスト)
	vector dp(n,vector(n+1,INF));
	rep(u,n) dp[u][0]=0;
	for(int u=n-1;u>=0;u--){
		for(auto [v,cost]:T[u]){
			auto next=dp[u];
			rep(k1,n+1){
				if(dp[u][k1]==INF) break;
				rep(k2,n+1){
					if(k1+k2>n || dp[v][k2]>cost) break;
					if(dp[v][k2]<cost){
						next[k1+k2]=min(next[k1+k2],dp[u][k1]+dp[v][k2]);
					}
					if(k1+k2+1<=n){
						next[k1+k2+1]=min(next[k1+k2+1],dp[u][k1]+cost);
					}
				}
			}
			dp[u]=next;
		}
	}

	int ans=0;
	rep(k,n+1) if(dp[0][k]<INF) ans=k+1;
	printf("%d\n",ans);

	return 0;
}
