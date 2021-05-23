#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	bool dp[501]={true};
	rep(i,n){
		bool next[501]={};
		rep(j,m){
			int a; scanf("%d",&a);
			rep(w,k-a+1) if(dp[w]) next[w+a]=true;
		}
		copy(next,next+k+1,dp);
	}

	int res=k+1;
	rep(w,k+1) if(dp[w]) res=w;
	printf("%d\n",k-res);

	return 0;
}
