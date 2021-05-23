#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

const int INF=1<<29;

int win,draw;
int f(char c1,char c2){
	if((c1=='G' && c2=='C')
	|| (c1=='C' && c2=='P')
	|| (c1=='P' && c2=='G')) return win;
	else if(c1==c2) return draw;
	else return 0;
}

int main(){
	int n,m,k; scanf("%d%d%d%d%d",&n,&m,&k,&win,&draw);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	vector<char> s(n);
	rep(i,n) scanf(" %c",&s[i]);

	static int dp[2001][2000];
	rep(t,k+1) rep(u,n) dp[t][u]=-INF;
	dp[0][0]=0;
	rep(t,k){
		int op; scanf("%d",&op); op--;
		rep(u,n) if(dp[t][u]!=-INF) {
			dp[t+1][u]=max(dp[t+1][u],dp[t][u]+f(s[u],s[op]));
			for(int v:G[u]){
				dp[t+1][v]=max(dp[t+1][v],dp[t][u]+f(s[v],s[op]));
			}
		}
	}
	printf("%d\n",*max_element(dp[k],dp[k]+n));

	return 0;
}
