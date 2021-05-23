#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,v[1000],w[1000],V;
	scanf("%d",&n);
	rep(i,n) scanf("%d%d",&v[i],&w[i]);
	scanf("%d",&V);

	int dp[100001];
	rep(a,1e5+1) dp[a]=-INF;
	dp[0]=0;
	rep(i,n){
		for(int a=1e5;a>=w[i];a--) dp[a]=max(dp[a],dp[a-w[i]]+v[i]);
	}

	rep(l,1e5+1) if(dp[l]==V) {
		printf("%d\n",l>0?l:1);

		if(accumulate(v,v+n,0)==V){
			puts("inf");
		}
		else{
			int r;
			for(r=l+1;r<=1e5;r++) if(dp[r]>V) break;
			printf("%d\n",r-1);
		}
		break;
	}

	return 0;
}
