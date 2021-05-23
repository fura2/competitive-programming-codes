#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

template<class T> struct interval{
	T l,r;
	interval():l(T{}),r(T{}){}
	interval(const T& l,const T& r):l(l),r(r){}
	bool operator<(const interval& I)const{ return make_tuple(l,r)<make_tuple(I.l,I.r); }
};

int main(){
	lint n,d,t; cin>>n>>d>>t;
	vector<lint> x(n);
	rep(i,n) cin>>x[i], x[i]+=1e9;

	map<lint,vector<interval<lint>>> S;
	rep(i,n){
		S[x[i]%d].emplace_back(x[i]/d-t,x[i]/d+t);
	}

	lint ans=0;
	for(auto& p:S){
		auto& I=p.second;
		sort(I.begin(),I.end());

		lint pre=-INF;
		for(auto& J:I){
			ans+=max(J.r-max(pre,J.l)+1,0LL);
			pre=max(pre,J.r+1);
		}
	}
	cout<<ans<<'\n';

	return 0;
}
