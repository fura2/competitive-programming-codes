#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a;
	string s; cin>>a>>s;

	bool ok=(a==0);
	for(char c:s){
		if(c=='+') a++;
		else       a--;
		if(a==0) ok=true;
	}
	puts(ok?"Yes":"No");

	return 0;
}
