#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> d(n),len(n);
	vector<lint> score(n);
	rep(i,n) scanf("%d%d%lld",&d[i],&len[i],&score[i]);

	vector<int> p(n);
	iota(p.begin(),p.end(),0);
	sort(p.begin(),p.end(),[&](int i,int j){
		return d[i]>d[j];
	});

	vector<lint> dp(5001);
	for(int i:p){
		rep(t,d[i]-len[i]+1){
			dp[t]=max(dp[t],dp[t+len[i]]+score[i]);
		}
	}
	printf("%lld\n",*max_element(dp.begin(),dp.end()));

	return 0;
}
