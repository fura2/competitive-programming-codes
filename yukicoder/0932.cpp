#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();
	string t;
	rep(i,(n+1)/3) t+="AC,";
	t.pop_back();
	puts(s==t?"Done!":"Failed...");
	return 0;
}
