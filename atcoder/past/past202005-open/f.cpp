#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	vector<string> s(n);
	rep(i,n){
		cin>>s[i];
		sort(s[i].begin(),s[i].end());
		s[i].erase(unique(s[i].begin(),s[i].end()),s[i].end());
	}

	string ans(n,'?');
	rep(i,(n+1)/2){
		for(char c1:s[i]) for(char c2:s[n-1-i]) if(c1==c2) ans[i]=ans[n-1-i]=c1;
		if(ans[i]=='?') return puts("-1"),0;
	}
	cout<<ans<<'\n';

	return 0;
}
