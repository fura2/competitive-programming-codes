#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int x=0,y=0;
	for(char c:s){
		if(c=='N') y++;
		if(c=='E') x++;
		if(c=='W') x--;
		if(c=='S') y--;
	}
	cout<<hypot(x,y)<<'\n';
	return 0;
}
