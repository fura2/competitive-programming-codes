#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s;
	int w; cin>>s>>w;

	for(int i=0;i<s.length();i+=w) putchar(s[i]);
	puts("");

	return 0;
}
