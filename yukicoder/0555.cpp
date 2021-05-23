#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n,c,v; scanf("%d%d%d",&n,&c,&v);

	vector<lint> dp(2*n+1,INF);
	dp[1]=0;
	for(int i=1;i<=2*n;i++){
		lint cost=c;
		for(int j=2*i;j<=2*n;j+=i){
			cost+=v;
			dp[j]=min(dp[j],dp[i]+cost);
		}
	}
	printf("%lld\n",*min_element(dp.begin()+n,dp.end()));

	return 0;
}
