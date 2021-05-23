#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	for(char& c:s) c=(c-'A'+23)%26+'A';
	cout<<s<<'\n';
	return 0;
}
