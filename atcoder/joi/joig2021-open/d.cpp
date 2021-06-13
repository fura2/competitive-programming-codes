#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,m;
	lint d; scanf("%d%d%lld",&n,&m,&d);

	vector<lint> x(n),v(n);
	{
		vector<pair<lint,lint>> p(n);
		rep(i,n) scanf("%lld%lld",&p[i].first,&p[i].second);
		sort(p.begin(),p.end());
		rep(i,n) tie(x[i],v[i])=p[i];
	}

	auto check=[&](lint th){
		int cnt=0;
		lint pre=-2e9;
		rep(i,n) if(v[i]>=th) {
			if(x[i]-pre>=d){
				pre=x[i];
				cnt++;
			}
		}
		return cnt>=m;
	};

	if(!check(0)){
		puts("-1");
		return 0;
	}

	lint lo=0,hi=1e9+1;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;
		if(check(mi)) lo=mi;
		else          hi=mi;
	}
	printf("%lld\n",lo);

	return 0;
}
