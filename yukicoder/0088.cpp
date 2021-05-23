#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int cnt=0;
	rep(i,8){
		string b; cin>>b;
		cnt+=8-count(b.begin(),b.end(),'.');
	}
	cout<<((cnt%2==0)==(s=="oda")?"oda":"yukiko")<<'\n';
	return 0;
}
