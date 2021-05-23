#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T> struct interval{
	T l,r;
	interval():l(T{}),r(T{}){}
	interval(const T& l,const T& r):l(l),r(r){}
	bool operator<(const interval& I)const{ return make_tuple(r,l)<make_tuple(I.r,I.l); }
};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<interval<int>> I(n);
	rep(i,n) scanf("%d%d",&I[i].l,&I[i].r), I[i].r++;
	multiset<int> A;
	rep(i,m){ int a; scanf("%d",&a); A.emplace(a); }

	sort(I.begin(),I.end());

	int ans=0;
	for(auto J:I){
		auto it=A.lower_bound(J.l);
		if(it!=A.end() && *it<J.r){
			A.erase(it);
			ans++;
		}
	}
	printf("%d\n",ans);

	return 0;
}
