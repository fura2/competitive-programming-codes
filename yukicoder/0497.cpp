#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	vector a(n,vector(3,0));
	rep(i,n){
		rep(j,3) cin>>a[i][j];
		sort(a[i].begin(),a[i].end());
	}

	sort(a.begin(),a.end());

	vector<int> dp(n,1);
	rep(i,n) rep(j,i) if(a[j][0]<a[i][0] && a[j][1]<a[i][1] && a[j][2]<a[i][2]) {
		dp[i]=max(dp[i],dp[j]+1);
	}
	printf("%d\n",*max_element(dp.begin(),dp.end()));

	return 0;
}
