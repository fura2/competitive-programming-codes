#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

vector<long long> divisors(long long a){
	vector<long long> res;
	for(long long i=1;i*i<=a;i++) if(a%i==0) {
		res.emplace_back(i);
		if(i*i<a) res.emplace_back(a/i);
	}
	sort(res.begin(),res.end());
	return res;
}


int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<lint> D;
	rep(i,n) for(lint d:divisors(a[i])) D.emplace_back(d);
	sort(D.begin(),D.end());
	D.erase(unique(D.begin(),D.end()),D.end());

	int m=D.size();
	vector<lint> dp(m); // dp[i] = (gcd が D[i] になる部分列の総数)
	for(int i=m-1;i>=0;i--){
		int cnt=0;
		rep(j,n) if(a[j]%D[i]==0) cnt++;
		dp[i]=(1LL<<cnt)-1;
		for(int k=i+1;k<m;k++) if(D[k]%D[i]==0) dp[i]-=dp[k];
	}
	printf("%lld\n",dp[0]);

	return 0;
}
