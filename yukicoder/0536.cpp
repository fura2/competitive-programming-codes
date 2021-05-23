#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();
	if(s.substr(n-2)=="ai") cout<<s.substr(0,n-2)<<"AI\n";
	else cout<<s<<"-AI\n";
	return 0;
}
