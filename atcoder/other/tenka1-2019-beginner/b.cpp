#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k;
	string s; cin>>n>>s>>k; k--;

	rep(i,n) if(s[i]!=s[k]) s[i]='*';
	cout<<s<<'\n';

	return 0;
}
