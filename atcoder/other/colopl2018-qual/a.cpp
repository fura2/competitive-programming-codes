#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b;
	string s; cin>>a>>b>>s;
	puts(a<=s.length()&&s.length()<=b?"YES":"NO");
	return 0;
}
