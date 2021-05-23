#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;
	rep(i,n-2) if(s.substr(i,3)=="joi") s[i]='J', s[i+1]='O', s[i+2]='I';
	cout<<s<<'\n';
	return 0;
}
