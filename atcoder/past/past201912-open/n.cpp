#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

template<class T> struct interval{
	T l,r;
	lint wt;
	interval():l(T{}),r(T{}){}
	interval(const T& l,const T& r,lint wt):l(l),r(r),wt(wt){}
	bool operator<(const interval& I)const{ return make_tuple(l,r)<make_tuple(I.l,I.r); }
};

int main(){
	int n;
	lint w,c; scanf("%d%lld%lld",&n,&w,&c);

	vector<interval<lint>> I(n);
	rep(i,n) scanf("%lld%lld%lld",&I[i].l,&I[i].r,&I[i].wt);
	I.emplace_back(-1,0,(lint)1e15);
	I.emplace_back(w,w+1,(lint)1e15);
	n+=2;

	lint ans=INF;
	rep(_,2){
		sort(I.begin(),I.end());
		vector<lint> sum(n+1);
		rep(i,n) sum[i+1]+=sum[i]+I[i].wt;

		vector<pair<lint,int>> Ev(2*n);
		rep(i,n){
			Ev[2*i+0]={I[i].l,i+1};
			Ev[2*i+1]={I[i].r,-(i+1)};
		}
		sort(Ev.begin(),Ev.end());

		lint cost=0;
		for(auto e:Ev){
			if(e.second>0){
				int id=e.second-1;
				cost+=I[id].wt;
			}
			else{
				int id=-e.second-1;
				cost-=I[id].wt;
				int a=lower_bound(I.begin(),I.end(),interval<lint>(I[id].r,I[id].r,0))-I.begin();
				int b=lower_bound(I.begin(),I.end(),interval<lint>(I[id].r+c,I[id].r+c,0))-I.begin();
				if(I[id].r+c<=w){
					ans=min(ans,cost+sum[b]-sum[a]);
				}
			}
		}

		rep(i,n) tie(I[i].l,I[i].r)=make_pair(w-I[i].r,w-I[i].l);
	}

	printf("%lld\n",ans);

	return 0;
}
