#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	reverse(s.begin(),s.end());

	bool ok=true;
	int phase=0,carry=0;
	rep(i,n){
		int a=s[i]-'0'-carry;
		if(2<=a && a<=4){
			if(phase>=2) ok=false;
			phase=1;
			carry=1;
		}
		else if(6<=a && a<=7){
			if(phase==0 || phase==3) ok=false;
			phase=2;
			carry=0;
		}
		else if(a==0){
			if(phase!=1) ok=false;
			phase=3;
			carry=0;
		}
		else ok=false;
	}
	if(carry!=0) ok=false;
	puts(ok?"Yes":"No");

	return 0;
}
