#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	int dp[100001]={};
	rep(i,n) if(s[i]=='5' || s[i]=='?') {
		if(i>0 && (s[i-1]=='2' || s[i-1]=='?')) dp[i+1]=dp[i-1]+2;
	}
	cout<<*max_element(dp,dp+n+1)<<endl;

	return 0;
}
