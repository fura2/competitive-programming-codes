#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	rep(i,6) if(s.substr(i,2)=="ao") s[i]='k', s[i+1]='i';
	cout<<s<<'\n';
	return 0;
}
