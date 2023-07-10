#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();
	rep(i,8) if(s.substr(0,i)+s.substr(i+n-7)=="keyence") return puts("YES"),0;
	puts("NO");
	return 0;
}
