#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	rep(i,26) if(s[i]!='a'+i) {
		printf("%cto%c\n",'a'+i,s[i]);
		break;
	}
	return 0;
}
