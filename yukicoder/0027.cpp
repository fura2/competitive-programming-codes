#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<20;

int main(){
	int v[4];
	rep(i,4) scanf("%d",&v[i]);

	int ans=INF;
	for(int a=1;a<=30;a++) for(int b=a;b<=30;b++) for(int c=b;c<=30;c++) {
		int res=0;
		rep(i,4){
			int dp[31];
			rep(w,v[i]+1) dp[w]=(w==0?0:INF);
			rep(w,v[i]+1-a) dp[w+a]=min(dp[w+a],dp[w]+1);
			rep(w,v[i]+1-b) dp[w+b]=min(dp[w+b],dp[w]+1);
			rep(w,v[i]+1-c) dp[w+c]=min(dp[w+c],dp[w]+1);
			res+=dp[v[i]];
		}
		ans=min(ans,res);
	}
	printf("%d\n",ans);

	return 0;
}
