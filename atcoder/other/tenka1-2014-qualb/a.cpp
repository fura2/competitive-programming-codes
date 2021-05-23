#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int pos=s.find("HAGIYA");
	cout<<s.substr(0,pos+4)<<"XILE"<<s.substr(pos+6)<<'\n';
	return 0;
}
