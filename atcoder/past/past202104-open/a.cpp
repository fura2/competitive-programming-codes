#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	bool ok=true;
	rep(i,8){
		if(i==3){
			if(s[i]!='-') ok=false;
		}
		else{
			if(!isdigit(s[i])) ok=false;
		}
	}
	puts(ok?"Yes":"No");
	return 0;
}
