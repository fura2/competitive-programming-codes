#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int n,k,a[18];

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<lint> dp(1<<n);
	dp[0]=1;
	rep(S,1<<n){
		vector<int> P;
		rep(i,n) if(~S>>i&1) P.emplace_back(i);

		if(P.size()>=1){
			dp[S|1<<P[0]]+=dp[S];
		}
		if(P.size()>=2){
			for(int i=1;i<P.size();i++){
				if(a[P[0]]+a[P[i]]<=2*k){
					dp[S|1<<P[0]|1<<P[i]]+=dp[S];
				}
			}
		}
		if(P.size()>=3){
			for(int i=1;i<P.size();i++){
				for(int j=i+1;j<P.size();j++){
					if(a[P[0]]+a[P[i]]+a[P[j]]<=3*k){
						dp[S|1<<P[0]|1<<P[i]|1<<P[j]]+=dp[S];
					}
				}
			}
		}
	}
	printf("%lld\n",dp[(1<<n)-1]);

	return 0;
}
