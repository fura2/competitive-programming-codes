#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	cout<<(s[0]==s[2]&&s[1]==s[3]?"Yes":"No")<<'\n';
	return 0;
}
