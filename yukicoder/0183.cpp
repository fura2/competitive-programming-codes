#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	bool dp[1<<15]={true};
	rep(i,n) rep(x,1<<15) if(dp[x]) dp[x^a[i]]=true;

	printf("%ld\n",count(dp,dp+(1<<15),true));

	return 0;
}
