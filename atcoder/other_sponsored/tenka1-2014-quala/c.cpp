#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,m; cin>>n>>m;
	string s[14];
	rep(i,n) cin>>s[i];

	bool A[14][14]={};
	rep(i,n) for(int j=i;j<n;j++) {
		A[i][j]=A[j][i]=true;
		rep(k,m) if(s[i][k]!='*' && s[j][k]!='*' && s[i][k]!=s[j][k]) {
			A[i][j]=A[j][i]=false;
			break;
		}
	}

	bool clique[1<<14]={};
	rep(S,1<<n){
		clique[S]=true;
		rep(i,n) if(S>>i&1) for(int j=i+1;j<n;j++) if(S>>j&1) {
			if(!A[i][j]) clique[S]=false;
		}
	}

	vector<int> dp(1<<n,INF);
	dp[0]=0;
	rep(S,1<<n){
		for(int T=(1<<n)-1;T>=0;T--){
			T&=S;
			if(clique[S&~T]){
				dp[S]=min(dp[S],dp[T]+1);
			}
		}
	}
	printf("%d\n",dp[(1<<n)-1]);

	return 0;
}
