#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector A(n,vector(n,make_pair(INF,0LL)));
	rep(i,m){
		int u,v;
		lint c,t; scanf("%d%d%lld%lld",&u,&v,&c,&t); u--; v--;
		A[u][v]=A[v][u]={c,t};
	}

	vector dp1(1<<n,vector(n,INF));
	dp1[0][0]=0;
	rep(S,1<<n) rep(u,n) if(u==0 || S>>u&1) {
		rep(v,n) if(~S>>v&1) {
			auto [c,t]=A[u][v];
			if(dp1[S][u]+c<=t){
				dp1[S|1<<v][v]=min(dp1[S|1<<v][v],dp1[S][u]+c);
			}
		}
	}

	vector dp2(1<<n,vector(n,0LL));
	dp2[0][0]=1;
	rep(S,1<<n) rep(u,n) if(u==0 || S>>u&1) {
		rep(v,n) if(~S>>v&1) {
			auto [c,t]=A[u][v];
			if(dp1[S][u]+c<=t && dp1[S][u]+c==dp1[S|1<<v][v]){
				dp2[S|1<<v][v]+=dp2[S][u];
			}
		}
	}

	if(dp1[(1<<n)-1][0]<INF){
		printf("%lld %lld\n",dp1[(1<<n)-1][0],dp2[(1<<n)-1][0]);
	}
	else{
		puts("IMPOSSIBLE");
	}

	return 0;
}
