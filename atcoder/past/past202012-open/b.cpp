#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	string t;
	rep(i,n){
		string tmp;
		for(char c:t) if(c!=s[i]) tmp+=c;
		tmp+=s[i];
		t=tmp;
	}
	cout<<t<<'\n';

	return 0;
}
