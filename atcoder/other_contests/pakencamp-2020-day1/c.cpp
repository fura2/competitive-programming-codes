#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	map<string,int> f;
	rep(i,n){
		int m; cin>>m;
		rep(j,m){
			string s; cin>>s;
			++f[s];
		}
	}

	int ans=0;
	for(auto [s,c]:f) if(c==n) ans++;
	cout<<ans<<'\n';

	return 0;
}
