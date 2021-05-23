#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void solve(){
	int n1,n2,m; scanf("%d%d%d",&n1,&n2,&m);
	vector<int> a(m);
	rep(i,m) scanf("%d",&a[i]);

	sort(a.begin(),a.end());

	int ans=0;
	rep(i,m){
		int sum=accumulate(a.begin(),a.begin()+i+1,0);
		if(sum>n1+n2) break;

		vector<bool> dp(n1+1);
		dp[0]=true;
		rep(j,i+1){
			for(int x=n1;x>=a[j];x--) if(dp[x-a[j]]) dp[x]=true;
		}
		bool ok=false;
		rep(x,n1+1) if(dp[x] && sum-x<=n2) ok=true;
		if(ok) ans=i+1;
	}
	printf("%d\n",ans);
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
