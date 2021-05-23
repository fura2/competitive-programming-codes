#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	vector<string> s(n),t(n);
	rep(i,n) cin>>s[i]>>t[i];

	set<string> S(s.begin(),s.end()),T;
	rep(i,n) if(S.count(t[i])==0 && T.count(t[i])==0) {
		cout<<t[i]<<'\n';
		T.emplace(t[i]);
	}

	return 0;
}
