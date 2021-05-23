#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s[10];
	rep(i,10) cin>>s[i];

	bool ok=true;
	rep(j,10){
		bool tmp=false;
		rep(i,10) if(s[i][j]=='o') tmp=true;
		if(!tmp) ok=false;
	}
	puts(ok?"Yes":"No");

	return 0;
}
