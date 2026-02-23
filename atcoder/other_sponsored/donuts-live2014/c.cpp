#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> dp(n+1);
	rep(i,n){
		dp[i+1]=max(dp[i],0)+a[i];
	}
	printf("%d\n",*max_element(dp.begin()+1,dp.end()));

	return 0;
}
