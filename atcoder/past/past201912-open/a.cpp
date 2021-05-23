#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	if(isdigit(s[0]) && isdigit(s[1]) && isdigit(s[2])) cout<<2*stoi(s)<<'\n';
	else cout<<"error\n";
	return 0;
}
