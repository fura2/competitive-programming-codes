#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	vector<lint> dp1(n+1); // dp1[i] = ([0, i] について, i から始めて i で終わるときの最小コスト)
	vector<lint> dp2(n+1); // dp2[i] = ([0, i] について, i から始めて i より左で終わるときの最小コスト)
	vector<lint> dp3(n+1); // dp3[i] = ([i, n] について, i から始めて i で終わるときの最小コスト)
	vector<lint> dp4(n+1); // dp4[i] = ([i, n] について, i から始めて i より右で終わるときの最小コスト)
	lint sum=0;
	rep(i,n){
		sum+=a[i];
		dp1[i+1]=min(dp1[i]+(a[i]==0?2:a[i]%2),sum);
		dp2[i+1]=min(dp1[i],dp2[i])+(a[i]+1)%2;
	}
	sum=0;
	for(int i=n-1;i>=0;i--){
		sum+=a[i];
		dp3[i]=min(dp3[i+1]+(a[i]==0?2:a[i]%2),sum);
		dp4[i]=min(dp3[i+1],dp4[i+1])+(a[i]+1)%2;
	}

	lint ans=INF;
	rep(i,n+1) ans=min({ans,dp1[i]+dp3[i],dp1[i]+dp4[i],dp2[i]+dp3[i]});
	printf("%lld\n",ans);

	return 0;
}
