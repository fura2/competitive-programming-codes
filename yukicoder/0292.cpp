#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s;
	int i,j; cin>>s>>i>>j;
	if(i>j) swap(i,j);
	if(i==j) cout<<s.substr(0,i)+s.substr(i+1)<<'\n';
	else     cout<<s.substr(0,i)+s.substr(i+1,j-i-1)+s.substr(j+1)<<'\n';
	return 0;
}
