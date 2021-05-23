// intended solution

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	const int L=1e5;

	int n,cost; scanf("%d%d",&n,&cost);
	vector<pair<int,int>> Ev[L+1];
	rep(i,n){
		int l,r,wt; scanf("%d%d%d",&l,&r,&wt);
		Ev[r].emplace_back(l,wt);
	}

	int dp[L+1]={};
	for(int x=1;x<=L;x++){
		dp[x]=max(dp[x],dp[x-1]-cost);
		for(auto p:Ev[x]){
			int l,wt; tie(l,wt)=p;
			dp[x]=max(dp[x],dp[l]+wt-cost*(x-l));
		}
	}
	printf("%d\n",*max_element(dp,dp+L+1));

	return 0;
}
