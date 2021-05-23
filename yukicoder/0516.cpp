#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s[3];
	rep(i,3) cin>>s[i];
	sort(s,s+3);
	cout<<s[1]<<'\n';
	return 0;
}
