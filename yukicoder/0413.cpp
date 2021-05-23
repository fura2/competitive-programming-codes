#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint calc(lint d){
	return lint((-1+sqrt(1+4*d))/2.0);
}

int main(){
	vector<lint> ans;
	for(lint t=1e9;t>0;t--) if(t*t+t-1<=1e18) {
		lint s=calc(t*t+t-1);
		if(s==t){
			ans.emplace_back(t*t+t-1);
			if(ans.size()==1e5) break;
		}
	}
	rep(i,ans.size()) printf("%lld\n",ans[i]);

	return 0;
}
