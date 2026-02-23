#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	rep(i,n-1) if(i>=0 && s[i]=='W' && s[i+1]=='A') {
		s[i]='A';
		s[i+1]='C';
		i-=2;
	}
	cout<<s<<'\n';

	return 0;
}
