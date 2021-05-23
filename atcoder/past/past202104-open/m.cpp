#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	map<lint,lint> hist;
	set<tuple<int,int,lint>> I; // (left, right, value)
	rep(i,n){
		++hist[a[i]];
		I.emplace(i,i+1,a[i]);
	}

	lint res=0;
	for(auto [v,cnt]:hist) res+=cnt*(cnt-1);

	int q; scanf("%d",&q);
	rep(i,q){
		int l,r;
		lint v; scanf("%d%d%lld",&l,&r,&v); l--;

		// x = l, r のすぐ左に切れ目を入れる
		for(int x:{l,r}) if(x<n) {
			auto it=prev(I.lower_bound(make_tuple(x+1,-1,0LL)));
			auto [l0,r0,val0]=*it;
			if(l0<x){
				I.erase(it);
				I.emplace(l0,x,val0);
				I.emplace(x,r0,val0);
			}
		}

		auto it=I.lower_bound(make_tuple(l,-1,0LL));
		while(1){
			auto [l0,r0,v0]=*it;
			it=I.erase(it);

			lint h0=hist[v0];
			res-=h0*(h0-1)-(h0-(r0-l0))*(h0-(r0-l0)-1);
			hist[v0]-=r0-l0;

			if(r==r0) break;
		}

		I.emplace(l,r,v);
		lint h=hist[v];
		res+=(h+r-l)*(h+r-l-1)-h*(h-1);
		hist[v]+=r-l;

		printf("%lld\n",res/2);
	}

	return 0;
}
