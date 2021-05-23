#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	string ans=s;
	rep(i,s.length()) rep(j,i) {
		swap(s[i],s[j]);
		ans=max(ans,s);
		swap(s[i],s[j]);
	}
	cout<<ans<<'\n';
	return 0;
}
