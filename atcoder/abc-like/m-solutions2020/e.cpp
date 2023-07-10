#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int n;
lint x[15],y[15],p[15];
lint res[16][15],ans[16];

void dfs(int i,int num){
	if(i==n){
		ans[num]=min(ans[num],accumulate(res[n],res[n]+n,0LL));
		return;
	}

	rep(j,n) res[i+1][j]=res[i][j];
	dfs(i+1,num);

	// 縦
	rep(j,n) res[i+1][j]=min(res[i][j],p[j]*abs(x[j]-x[i]));
	dfs(i+1,num+1);

	// 横
	rep(j,n) res[i+1][j]=min(res[i][j],p[j]*abs(y[j]-y[i]));
	dfs(i+1,num+1);
}

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%lld%lld%lld",&x[i],&y[i],&p[i]);

	rep(j,n){
		res[0][j]=p[j]*min(abs(x[j]),abs(y[j]));
		ans[j]=INF;
	}
	dfs(0,0);

	rep(i,n+1) printf("%lld\n",ans[i]);

	return 0;
}
