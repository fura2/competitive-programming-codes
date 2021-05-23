#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

int main(){
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	weighted_graph<int> G(n);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		G[u].emplace_back(v,c);
		G[v].emplace_back(u,c);
	}

	bool dp[1001][100]={};
	rep(u,n) dp[0][u]=true;
	rep(t,k){
		int d; scanf("%d",&d);
		rep(u,n) if(dp[t][u]) {
			for(auto e:G[u]) if(e.wt==d) {
				dp[t+1][e.to]=true;
			}
		}
	}

	vector<int> ans;
	rep(u,n) if(dp[k][u]) ans.emplace_back(u);
	printf("%lu\n",ans.size());
	rep(i,ans.size()) printf("%d%c",ans[i]+1,i+1<ans.size()?' ':'\n');

	return 0;
}
