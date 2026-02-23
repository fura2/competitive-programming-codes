#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	bool dp[100001]={};
	rep(i,k+1) rep(j,n) if(a[j]<=i && !dp[i-a[j]]) dp[i]=true;

	puts(dp[k]?"First":"Second");

	return 0;
}
