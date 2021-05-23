#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string f="cqlmdrstfxyzbanopuvweghijk";
	string s; cin>>s;
	for(char& c:s) c=f[c-'a'];
	cout<<s<<'\n';
	return 0;
}
