#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	if     (s[2]=='B') cout<<"Bachelor";
	else if(s[2]=='M') cout<<"Master";
	else if(s[2]=='D') cout<<"Doctor";
	cout<<' '<<s.substr(0,2)<<'\n';
	return 0;
}
