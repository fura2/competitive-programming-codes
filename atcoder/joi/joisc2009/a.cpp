// Day 1: Sequence

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int m;
	lint p,q; cin>>m>>p>>q;
	vector<int> a(m);
	rep(i,m) cin>>a[i];

	int per=0,one=0,S0=0;
	rep(i,m) if(a[i]%2==1) {
		S0|=1<<i;
	}
	for(int S=S0;;){
		per++;
		if((S>>m-1&1)^(S&1)){
			one++;
			S>>=1;
			S|=1<<m-1;
		}
		else{
			S>>=1;
		}
		if(S==S0) break;
	}

	auto solve=[&](lint p){
		lint res=0;
		if(p<=m){
			rep(i,p) if(a[i]%2==1) res++;
			return res;
		}

		rep(i,m) if(a[i]%2==1) res++;
		p-=m;
		res+=p/per*one;
		p%=per;

		for(int S=S0;p>0;p--){
			if((S>>m-1&1)^(S&1)){
				res++;
				S>>=1;
				S|=1<<m-1;
			}
			else{
				S>>=1;
			}
		}
		return res;
	};

	cout<<solve(q)-solve(p-1)<<'\n';

	return 0;
}
