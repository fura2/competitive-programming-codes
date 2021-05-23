#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	pair<int,int> I[100000];
	rep(i,n){
		int x,r; scanf("%d%d",&x,&r);
		I[i]={x-r,x+r};
	}

	sort(I,I+n);

	int dp[100000];
	// naive O(n^2) DP
	/*
	rep(i,n){
		dp[i]=1;
		rep(j,i) if(I[i].second<I[j].second) dp[i]=max(dp[i],dp[j]+1);
	}
	*/
	map<int,int> f;
	f[INF]=0;
	rep(i,n){
		auto it=f.upper_bound(I[i].second);
		dp[i]=(it->second)+1;
		while(it!=f.begin()){
			--it;
			if(it->second<=dp[i]) it=f.erase(it);
		}
		f[I[i].second]=dp[i];
	}

	printf("%d\n",*max_element(dp,dp+n));

	return 0;
}
