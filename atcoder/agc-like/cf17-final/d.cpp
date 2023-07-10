#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=INT_MAX;

int main(){
	int n; scanf("%d",&n);
	vector<pair<int,int>> a(n);
	rep(i,n) scanf("%d%d",&a[i].first,&a[i].second);

	sort(a.begin(),a.end(),[](auto x,auto y){
		return x.first+x.second<y.first+y.second;
	});

	// dp[i][j] = (i 人目まで見て j 人が座布団を積んだときの高さの最小値)
	vector dp(n+1,vector(n+1,INF));
	dp[0][0]=0;
	rep(i,n){
		int h,p; tie(h,p)=a[i];
		rep(j,i+1) if(dp[i][j]<INF) {
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
			if(dp[i][j]<=h) dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+p);
		}
	}

	int ans=0;
	rep(j,n+1) if(dp[n][j]<INF) ans=j;
	printf("%d\n",ans);

	return 0;
}
