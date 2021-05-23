#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s;
	int n; cin>>s>>n;

	int ans=0;
	rep(i,n){
		string t; cin>>t;
		if((t+t).find(s)!=string::npos) ans++;
	}
	cout<<ans<<'\n';

	return 0;
}
