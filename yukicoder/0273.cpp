#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	int ans=1;
	rep(i,n) for(int j=i+1;j<=n;j++) {
		bool ok=(j-i<n);
		rep(k,j-i) if(s[i+k]!=s[j-k-1]) ok=false;
		if(ok) ans=max(ans,j-i);
	}
	cout<<ans<<'\n';

	return 0;
}
