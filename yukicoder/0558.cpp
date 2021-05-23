#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();
	rep(i,n-2) if(s.substr(i,3)=="575") return puts("YES"),0;
	puts("NO");
	return 0;
}
