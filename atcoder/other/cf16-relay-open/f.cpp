#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

// experiment
/*
int memo[1000];

int f(int n){
	int& res=memo[n];
	if(res!=-1) return res;

	if(n<=2) return res=0;

	res=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<n;j++){
			int a[3]={i,j-i,n-j};
			sort(a,a+3);
			res=max(res,f(a[1])+1);
		}
	}
	return res;
}

int main(){
	memset(memo,-1,sizeof memo);
	rep(i,300){
		printf("f(%d) = %d\n",i,f(i));
	}
	return 0;
}
*/

int main(){
	lint dp[41]={2};
	rep(i,40) dp[i+1]=2*dp[i]+2;

	int n; scanf("%d",&n);
	printf("%lld\n",dp[n]);

	return 0;
}
