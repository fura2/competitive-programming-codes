#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	set<pair<lint,lint>> I;
	multiset<lint> Sz;

	int q; scanf("%*lld%d",&q);
	rep(_,q){
		lint l,r; scanf("%lld%lld",&l,&r); r++;

		while(1){
			auto it=I.upper_bound({l,-INF});
			if(it!=I.end()){
				lint tl,tr; tie(tl,tr)=*it;
				if(tl<=r){
					r=max(r,tr);
					Sz.erase(Sz.find(tr-tl));
					I.erase(it);
					continue;
				}
			}

			it=I.upper_bound({l,-INF});
			if(it!=I.begin()){
				--it;
				lint tl,tr; tie(tl,tr)=*it;
				if(l<=tr){
					l=min(l,tl);
					r=max(r,tr);
					Sz.erase(Sz.find(tr-tl));
					I.erase(*it);
					continue;
				}
			}

			break;
		}
		Sz.emplace(r-l);
		I.emplace(l,r);

		printf("%lld\n",*Sz.rbegin());
	}

	return 0;
}
