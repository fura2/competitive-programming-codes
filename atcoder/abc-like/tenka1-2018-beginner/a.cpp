#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	if(s.length()==3) swap(s[0],s[2]);
	cout<<s<<'\n';
	return 0;
}
