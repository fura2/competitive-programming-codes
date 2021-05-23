#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; cin>>n;

	set<lint> ans;
	for(int i=1;i<=n;i++) ans.emplace(n/i);
	cout<<ans.size()<<'\n';

	return 0;
}
