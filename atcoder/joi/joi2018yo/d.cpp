#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int calc(vector<int> a,int mn){
	int n=a.size();
	vector<int> cum(n+1);
	rep(i,n) cum[i+1]=cum[i]+a[i];

	vector<int> dp(n+1,INF);
	dp[0]=0;
	for(int i=1;i<=n;i++){
		rep(j,i) if(cum[i]-cum[j]>=mn) dp[i]=min(dp[i],max(dp[j],cum[i]-cum[j]));
	}
	return dp[n];
}

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> cum(n+1);
	rep(i,n) cum[i+1]=cum[i]+a[i];

	int ans=INF;
	rep(i,n) for(int j=i+1;j<=n;j++) {
		if(i==0 && j==n) continue;
		int sum=cum[j]-cum[i];
		int tmpl=calc(vector<int>(a.begin(),a.begin()+i),sum);
		int tmpr=calc(vector<int>(a.begin()+j,a.end()),sum);
		if(tmpl<INF && tmpr<INF){
			ans=min(ans,max(tmpl,tmpr)-sum);
		}
	}
	printf("%d\n",ans);

	return 0;
}
