#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	for(char& c:s){
		if(c=='I' || c=='l') c='1';
		if(c=='O' || c=='o') c='0';
	}
	cout<<s<<'\n';
	return 0;
}
