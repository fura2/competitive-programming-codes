#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	vector<string> s(n);
	rep(i,n) cin>>s[i];

	string ans=s[0]+s[1];
	rep(i,n) rep(j,n) if(i!=j) ans=min(ans,s[i]+s[j]);
	cout<<ans<<'\n';

	return 0;
}
