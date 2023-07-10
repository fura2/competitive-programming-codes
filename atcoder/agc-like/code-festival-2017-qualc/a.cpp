#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	rep(i,s.length()-1) if(s[i]=='A' && s[i+1]=='C') return puts("Yes"),0;
	puts("No");
	return 0;
}
