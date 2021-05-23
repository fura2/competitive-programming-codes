#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint L;
	int n,q; cin>>L>>n>>q;
	set<lint> D={0,L};
	rep(i,n-1){
		lint d; cin>>d;
		D.emplace(d);
	}

	lint ans=0;
	rep(_,q){
		lint pos; cin>>pos;
		auto it=D.upper_bound(pos);
		ans+=min(*it-pos,pos-*prev(it));
	}
	cout<<ans<<'\n';

	return 0;
}
