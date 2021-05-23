#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,W; scanf("%d%d",&n,&W);

	vector<int> dp(W+1,-INF);
	dp[0]=0;
	rep(i,n){
		int v,w; scanf("%d%d",&v,&w);
		for(int x=W;x>=w;x--) dp[x]=max(dp[x],dp[x-w]+v);
	}
	printf("%d\n",*max_element(dp.begin(),dp.end()));

	return 0;
}
