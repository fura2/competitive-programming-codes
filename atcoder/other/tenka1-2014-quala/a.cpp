#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	vector<string> ans;
	for(int i=1;i<=1000;i++) ans.emplace_back(to_string(i));
	sort(ans.begin(),ans.end());
	rep(i,1000) cout<<ans[i]<<'\n';
	return 0;
}
