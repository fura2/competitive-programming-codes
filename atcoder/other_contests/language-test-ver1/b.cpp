#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	char c;
	string s; cin>>c>>s;
	rep(i,s.length()) if(s[i]!=c) cout<<s[i];
	cout<<'\n';
	return 0;
}
