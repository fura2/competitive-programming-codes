#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n),b(m),c(m);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,m) scanf("%d%d",&b[i],&c[i]);

	sort(a.begin(),a.end(),greater<>());

	vector<int> cum(n+1);
	rep(i,n) cum[i+1]=cum[i]+a[i];

	vector<int> dp(n+1,-1);
	dp[0]=0;
	rep(i,m){
		for(int x=n;x>=0;x--) if(dp[x]!=-1) {
			int x2=min(x+b[i],n);
			dp[x2]=max(dp[x2],dp[x]+cum[x2]-cum[x]-c[i]);
		}
	}
	printf("%d\n",*max_element(dp.begin(),dp.end()));

	return 0;
}
