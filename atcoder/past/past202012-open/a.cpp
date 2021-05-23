#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	rep(i,3){
		if(s[i]=='o' && s[i+1]=='o' && s[i+2]=='o') return puts("o"),0;
		if(s[i]=='x' && s[i+1]=='x' && s[i+2]=='x') return puts("x"),0;
	}
	puts("draw");

	return 0;
}
