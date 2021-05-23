#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int W,n; scanf("%d%d",&W,&n);
	vector<int> w(n),v(n);
	rep(i,n) scanf("%d",&w[i]);
	rep(i,n) scanf("%d",&v[i]);

	vector<int> dp(W+1,-INF);
	dp[0]=0;
	rep(i,n){
		int val=v[i];
		while(val>0){
			for(int x=W;x>=w[i];x--) dp[x]=max(dp[x],dp[x-w[i]]+val);
			val/=2;
		}
	}
	printf("%d\n",*max_element(dp.begin(),dp.end()));

	return 0;
}
