#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; cin>>n;

	lint ans=0;
	for(int len=1;len<=5;len++){
		for(lint a=1;;a++){
			string s=to_string(a);
			if(s.length()>len) break;
			s=string(len-s.length(),'0')+s;
			string t=s;
			reverse(t.begin(),t.end());

			lint x=stoll(t+s);
			if(x%10!=0 && x<lint(1e9) && lint(1e9+1)*x<=n) ans++;
		}
		for(lint a=1;;a++){
			string s=to_string(a);
			if(s.length()>len) break;
			s=string(len-s.length(),'0')+s;
			string t=s.substr(1);
			reverse(t.begin(),t.end());

			lint x=stoll(t+s);
			if(x%10!=0 && x<lint(1e9) && lint(1e9+1)*x<=n) ans++;
		}
	}
	cout<<ans<<'\n';

	return 0;
}
