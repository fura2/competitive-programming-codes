#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	string s[10],t[10];
	rep(i,n) cin>>s[i];
	rep(i,n) cin>>t[i];

	rep(i,n) if(s[i]!=t[i]) cout<<i+1<<'\n'<<s[i]<<'\n'<<t[i]<<'\n';

	return 0;
}
