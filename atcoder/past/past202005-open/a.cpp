#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s,t; cin>>s>>t;

	if(s==t) return puts("same"),0;

	for(char& c:s) c=tolower(c);
	for(char& c:t) c=tolower(c);
	if(s==t) return puts("case-insensitive"),0;

	puts("different");

	return 0;
}
