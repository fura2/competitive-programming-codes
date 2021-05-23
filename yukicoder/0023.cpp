#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,a,d; scanf("%d%d%d",&h,&a,&d);

	double dp[10001];
	dp[0]=0;
	for(int i=1;i<=h;i++){
		dp[i]=min(dp[max(i-a,0)]+1,dp[max(i-d,0)]+3.0/2);
	}
	printf("%.9f\n",dp[h]);

	return 0;
}
