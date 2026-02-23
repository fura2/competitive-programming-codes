#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	if(s=="{}"){
		puts("dict");
		return 0;
	}

	bool ok=false;
	int cnt=0;
	rep(i,s.length()){
		if(s[i]=='{') cnt++;
		if(s[i]=='}') cnt--;
		if(s[i]==':' && cnt==1) ok=true;
	}
	puts(ok?"dict":"set");

	return 0;
}
