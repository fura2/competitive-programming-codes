#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	string s; cin>>s;
	int n=s.length();

	lint ans=0;
	int cnt=0;
	rep(i,n){
		if(s[i]=='S') cnt++;
		if(i+2<n && s.substr(i,3)=="ing") ans+=cnt;
	}
	cout<<ans<<'\n';

	return 0;
}
