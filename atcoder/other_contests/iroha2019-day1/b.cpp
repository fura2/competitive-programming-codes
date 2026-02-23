#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s;
	int k; cin>>s>>k;

	rep(_,k) s=s.substr(1)+s[0];

	cout<<s<<'\n';

	return 0;
}
