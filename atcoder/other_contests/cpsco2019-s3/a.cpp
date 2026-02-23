#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	for(char& c:s){
		if     (c=='A') c='O';
		else if(c=='O') c='A';
	}
	cout<<s<<'\n';
	return 0;
}
