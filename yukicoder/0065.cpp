#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int k; scanf("%d",&k);
	double dp[26]={};
	for(int x=k-1;x>=0;x--){
		for(int i=1;i<=6;i++) dp[x]+=dp[x+i];
			dp[x]=dp[x]/6+1;
	}
	printf("%.9f\n",dp[0]);
	return 0;
}
