#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	int ans=0;
	char io='O';
	for(char c:s){
		if(c!=io) ans++, io=c;
	}
	if(ans>0 && io=='O') ans--;
	cout<<ans<<'\n';

	return 0;
}
