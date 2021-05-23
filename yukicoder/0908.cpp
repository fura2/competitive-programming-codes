#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s;
	getline(cin,s);
	bool ok=true;
	rep(i,s.length()){
		if(i%2==0 && !islower(s[i])) ok=false;
		if(i%2==1 && s[i]!=' ') ok=false;
	}
	puts(ok?"Yes":"No");
	return 0;
}
