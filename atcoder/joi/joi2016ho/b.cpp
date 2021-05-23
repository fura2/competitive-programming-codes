#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint solve(string s){
	int n=s.length();
	vector dp(n+1,vector(4,0LL));
	dp[0][0]=1;
	rep(i,n){
		rep(j,4) dp[i+1][j]+=dp[i][j];
		if(s[i]=='J') dp[i+1][1]+=dp[i][0];
		if(s[i]=='O') dp[i+1][2]+=dp[i][1];
		if(s[i]=='I') dp[i+1][3]+=dp[i][2];
	}
	return dp[n][3];
}

int main(){
	int n;
	string s; cin>>n>>s;

	lint res1=solve("J"+s);
	lint res2=solve(s+"I");

	vector<lint> Jcum(n+1),Icum(n+1);
	rep(i,n){
		Jcum[i+1]=Jcum[i]+(s[i]=='J'?1:0);
	}
	for(int i=n;i>0;i--){
		Icum[i-1]=Icum[i]+(s[i-1]=='I'?1:0);
	}

	lint tmp=0;
	rep(i,n+1) tmp=max(tmp,Jcum[i]*Icum[i]);

	cout<<max({res1,res2,solve(s)+tmp})<<'\n';

	return 0;
}
