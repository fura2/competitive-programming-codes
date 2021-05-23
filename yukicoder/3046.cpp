#pragma GCC optimize ("O3")
#pragma GCC target ("avx")

#include <cstdio>

using namespace std;

constexpr int MOD=1e9+7;

int k,n,f[100001],dp[100001];

int main(){
	scanf("%d%d",&k,&n);
	for(int i=0;i<n;i++){
		int a; scanf("%d",&a);
		f[a]=1;
	}

	dp[0]=1;
	for(int x=0;x<k;x++){
		int v=dp[x];
		for(int y=0;x+y<=k;y++){
			dp[x+y]+=f[y]*v;
			dp[x+y]-=MOD*(dp[x+y]>=MOD);
		}
	}
	printf("%d\n",dp[k]);

	return 0;
}
