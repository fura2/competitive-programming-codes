#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	string ans;
	rep(i,n){
		string s; cin>>s;
		ans+=s;
	}
	cout<<ans<<'\n';
	return 0;
}
