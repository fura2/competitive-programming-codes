#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,x; scanf("%d%d",&n,&x);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]);

	bool ok=false;
	int plus=0,minus=0;
	rep(i,n){
		if(a[i]>=x){
			ok=true;
			plus+=a[i]-x;
		}
		else{
			minus+=x-a[i];
		}
	}
	if(!ok) return puts("-1"),0;

	if(plus>=minus) return puts("0"),0;

	vector dp(50001,INF); // dp[i] = (i 点増やすために必要な最小コスト)
	dp[0]=0;
	rep(i,n) if(a[i]<x) {
		for(int w=50000;w>=x-a[i];w--) dp[w]=min(dp[w],dp[w-(x-a[i])]+b[i]);
	}
	printf("%d\n",*min_element(dp.begin()+minus-plus,dp.end()));

	return 0;
}
