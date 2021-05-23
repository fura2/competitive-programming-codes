#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool is_prime(long long a){
	if(a%2==0) return a==2;
	for(long long i=3;i*i<=a;i+=2) if(a%i==0) return false;
	return a!=1;
}

int main(){
	int m,n; scanf("%d%d",&m,&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector dp(m+1,-1);
	dp[m]=0;
	rep(i,n){
		for(int x=m;x>=a[i];x--) if(dp[x]!=-1) {
			dp[x-a[i]]=max(dp[x-a[i]],dp[x]+1);
		}
	}

	int ans=0;
	rep(x,m) if(dp[x]!=-1 && is_prime(x)) ans+=dp[x];
	ans+=m/(*min_element(a.begin(),a.end()));
	printf("%d\n",ans);

	return 0;
}
