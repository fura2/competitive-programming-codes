#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

template<class T> struct interval{
	T l,r;
	interval(){}
	interval(const T& l,const T& r):l(l),r(r){}
	bool operator<(const interval& I)const{ return make_tuple(l,r)<make_tuple(I.l,I.r); }
};

bool check(const vector<interval<int>>& I){
	int n=I.size();
	vector Ev(n,vector<int>());
	rep(i,n) Ev[I[i].l].emplace_back(I[i].r);

	priority_queue<int,vector<int>,greater<>> Q;
	rep(x,n){
		for(auto e:Ev[x]) Q.emplace(e);
		while(!Q.empty() && Q.top()<=x) Q.pop();
		if(Q.empty()) return false;
		Q.pop();
	}
	return true;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> t(n),a(n),b(n);
	rep(i,n) scanf("%d%d%d",&t[i],&a[i],&b[i]), t[i]--;

	lint lo=-INF,hi=INF;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;

		vector<interval<int>> I(n);
		rep(i,n){
			int l,r;
			if(a[i]<mi){
				l=r=t[i];
			}
			else{
				l=max<lint>(t[i]-(a[i]-mi)/b[i],0);
				r=min<lint>(t[i]+(a[i]-mi)/b[i]+1,n);
			}
			I[i]={l,r};
		}

		if(check(I)) lo=mi;
		else         hi=mi;
	}
	printf("%lld\n",lo);

	return 0;
}
