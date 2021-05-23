#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> dp(n+2),pre(n+2);
	for(int i=2;i<=n+1;i++){
		if(dp[i-1]<=dp[i-2]+a[i-2]){
			dp[i]=dp[i-2]+a[i-2];
			pre[i]=i-2;
		}
		else{
			dp[i]=dp[i-1];
			pre[i]=i-1;
		}
	}

	vector<int> ans;
	int idx=max_element(dp.begin(),dp.end())-dp.begin();
	printf("%d\n",dp[idx]);
	while(idx>=2){
		if(idx-pre[idx]==2) ans.emplace_back(idx);
		idx=pre[idx];
	}
	reverse(ans.begin(),ans.end());
	rep(i,ans.size()) printf("%d%c",ans[i]-1,i+1<ans.size()?' ':'\n');

	return 0;
}
