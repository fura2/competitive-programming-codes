#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	rep(i,s.length()/4) if(s.substr(4*i,4)=="post") {
		cout<<i+1<<'\n';
		return 0;
	}
	cout<<"none\n";
	return 0;
}
