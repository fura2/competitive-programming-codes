#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; cin>>n>>k;
	vector<string> s(n);
	rep(i,n) cin>>s[i];

	sort(s.rbegin(),s.rend());

	rep(i,n) cout<<s[i];
	cout<<'\n';

	return 0;
}
