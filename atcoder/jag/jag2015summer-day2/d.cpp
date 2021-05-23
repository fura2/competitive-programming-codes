#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	vector<int> dark(m);
	rep(i,m) scanf("%d",&dark[i]), dark[i]--;
	vector to(n,vector<int>(k));
	rep(u,n) rep(i,k) scanf("%d",&to[u][i]), to[u][i]--;

	vector<int> id(n,-1);
	rep(i,m) id[dark[i]]=i;

	vector nxt(k,vector(1<<m,0));
	rep(i,k) rep(S,1<<m) {
		rep(j,m) if(S>>j&1) {
			int u=dark[j];
			if(id[to[u][i]]!=-1){
				nxt[i][S]|=1<<id[to[u][i]];
			}
		}
	}

	vector dp(1<<m,INF);
	dp[(1<<m)-1]=0;
	while(1){
		bool updated=false;
		for(int S=(1<<m)-1;S>=0;S--) if(dp[S]<INF) {
			rep(i,k){
				if(dp[nxt[i][S]]>dp[S]+1){
					dp[nxt[i][S]]=dp[S]+1;
					updated=true;
				}
			}
		}
		if(!updated) break;
	}
	printf("%d\n",dp[0]);

	return 0;
}
