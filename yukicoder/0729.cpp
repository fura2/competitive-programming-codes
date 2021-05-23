#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s;
	int i,j; cin>>s>>i>>j;
	swap(s[i],s[j]);
	cout<<s<<'\n';
	return 0;
}
