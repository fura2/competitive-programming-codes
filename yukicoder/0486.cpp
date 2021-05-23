#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	rep(i,(int)s.length()-2) if(s[i]==s[i+1] && s[i]==s[i+2]) return puts(s[i]=='O'?"East":"West"),0;
	puts("NA");
	return 0;
}
