#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,W,m; cin>>n>>W>>m;
	vector<pair<int,int>> gr[50];
	rep(i,n){
		int w,v,c; cin>>w>>v>>c; c--;
		gr[c].emplace_back(w,v);
	}

	// dp[i][a] = ( i 色以下使ったときの重さ a での最大価値 )
	int dp[51][10001];
	rep(i,m+1) rep(a,W+1) dp[i][a]=-1;
	dp[0][0]=0;
	rep(c,50) if(!gr[c].empty()) {
		for(int i=m-1;i>=0;i--){
			int next[10001];
			rep(a,W+1) next[a]=dp[i][a];

			for(auto x:gr[c]){
				int w=x.first,v=x.second;
				for(int a=W-w;a>=0;a--) if(~next[a]) next[a+w]=max(next[a+w],next[a]+v);
			}

			rep(a,W+1) dp[i+1][a]=max(dp[i+1][a],next[a]);
		}
	}

	cout<<*max_element(dp[m],dp[m]+W+1)<<endl;

	return 0;
}
