#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	sort(a.begin(),a.end());

	vector<lint> X;
	rep(i,n){
		for(int d=-2;d<=2;d++){
			if(a[i]+d>0) X.emplace_back(a[i]+d);
		}
	}
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	int m=X.size();

	vector<lint> dp(m);
	rep(i,m){
		if(binary_search(a.begin(),a.end(),X[i])){
			dp[i]+=1;
		}
		if(binary_search(a.begin(),a.end(),X[i]-1)){
			int idx=lower_bound(X.begin(),X.end(),X[i]-2)-X.begin();
			if(idx>=0 && X[idx]==X[i]-2){
				dp[i]+=dp[idx];
			}
		}
	}
	printf("%lld\n",accumulate(dp.begin(),dp.end(),0LL));

	return 0;
}
