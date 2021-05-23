#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;

	int ans=100;
	rep(i,n){
		string s; cin>>s;
		int cnt=0;
		while(!s.empty() && s.back()=='0') s.pop_back(), cnt++;
		ans=min(ans,cnt);
	}
	cout<<ans<<'\n';

	return 0;
}
