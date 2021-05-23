#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();
	puts(s.substr(0,n/2)==s.substr(n/2)?"YES":"NO");
	return 0;
}
