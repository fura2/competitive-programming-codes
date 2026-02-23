#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	string s;
	lint k; cin>>s>>k;

	int n=s.length();

	static int next[1000001][26];
	rep(c,26) next[n][c]=n;
	for(int i=n-1;i>=0;i--){
		rep(c,26) next[i][c]=next[i+1][c];
		next[i][s[i]-'a']=i;
	}

	lint dp[1000001]; // dp[i] := number of subsequences of s[i..)
	// then, dp[i+1] = number of subsequences of s[i..) which start at s[i]
	dp[n]=1;
	for(int i=n-1;i>=0;i--){
		int pos=next[i+1][s[i]-'a'];
		if(pos==n){
			dp[i]=2*dp[i+1];
		}
		else{
			dp[i]=2*dp[i+1]-dp[pos+1];
		}
		dp[i]=min(dp[i],k+1); // avoid overflow
	}

	if(dp[0]<=k){ cout<<"Eel"<<endl; return 0; }

	string ans;
	for(int pos=0;k>0;){
		int c;
		for(c=0;;c++){
			int pos2=next[pos][c];
			if(pos2<n && k<=dp[pos2+1]) break;
			if(pos2<n) k-=dp[pos2+1];
		}
		k--;
		ans+='a'+c;
		pos=next[pos][c]+1;
	}
	cout<<ans<<endl;

	return 0;
}
