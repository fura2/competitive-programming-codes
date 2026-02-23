#include <bits/stdc++.h>
#include "grader.h"

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

typedef long long lint;

const long long INF=1LL<<61;

lint getT(int n,lint m){
	m++;

	if(n==1){
		int x;
		for(x=0;compare(x)==0;x++);
		return x;
	}

	static lint dp[51][20000];
	rep(j,20000) dp[0][j]=1;
	for(int i=1;i<=n;i++){
		dp[i][0]=1;
		for(int j=1;j<20000;j++) dp[i][j]=min(dp[i-1][j-1]+dp[i][j-1],INF);
	}

	lint ans=0;
	int c=19999;
	while(m>1){
		while(c>0 && dp[n][c-1]>m) c--;

		int res=compare(ans+dp[n-1][c-1]-1);
		if(res==1){
			m=dp[n-1][c-1];
			n--;
			c--;
		}
		else{
			m-=dp[n-1][c-1];
			ans+=dp[n-1][c-1];
			c--;
		}
	}
	return ans;
}
