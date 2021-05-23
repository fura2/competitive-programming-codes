#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	puts(s.substr(0,3)=="yah"&&s[3]==s[4]?"YES":"NO");
	return 0;
}
