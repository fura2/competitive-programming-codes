#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%*d%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<lint> freq(1e6+1);
	rep(i,n) freq[a[i]]++;

	vector<lint> dp(1e6+1); // dp[d]=(gcd(a[i],b)=d となる (i,b) の個数)
	for(int d=1e6;d>0;d--){
		for(int j=1;j*d<=1e6;j++){
			dp[d]+=j*freq[j*d];
			if(j>=2) dp[d]-=dp[j*d];
		}
	}

	lint ans=0;
	for(int d=1;d<=1e6;d++) ans+=dp[d]*d;
	rep(i,n) ans-=a[i];
	printf("%lld\n",ans);

	return 0;
}
