#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	sort(s.rbegin(),s.rend());
	if(!prev_permutation(s.begin(),s.end()) || s[0]=='0') puts("-1");
	else{
		for(char c:s) putchar(c);
		puts("");
	}
	return 0;
}
