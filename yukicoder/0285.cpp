#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; cin>>n;
	string s=to_string(n*108);
	cout<<s.substr(0,s.length()-2)+"."+s.substr(s.length()-2)<<'\n';
	return 0;
}
