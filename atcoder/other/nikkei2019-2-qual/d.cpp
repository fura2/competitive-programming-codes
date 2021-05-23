#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint INF=1LL<<61;

template<class T>
class segment_tree{
	int n;
	vector<T> dat;

	T query(int l,int r,int a,int b,int u){
		if(l<=a && b<=r) return dat[u];

		T res=INF;
		int c=(a+b)/2;
		if(l<c && a<r) res=min(res,query(l,r,a,c,2*u+1));
		if(l<b && c<r) res=min(res,query(l,r,c,b,2*u+2));
		return res;
	}

public:
	segment_tree(int N){
		for(n=1;n<N;n*=2);
		dat.assign(2*n-1,INF);
	}

	void update(int u,T v){
		u+=n-1;
		dat[u]=min(dat[u],v);
		while(u>0) u=(u-1)/2, dat[u]=min(dat[2*u+1],dat[2*u+2]);
	}

	T query(int l,int r){ return query(l,r,0,n,0); }
};

struct interval{
	int l,r;
	lint wt;
	bool operator<(const interval& I)const{ return r<I.r; }
};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<interval> I(m);
	rep(i,m){
		scanf("%d%d%lld",&I[i].l,&I[i].r,&I[i].wt);
		I[i].l--;
	}

	sort(I.begin(),I.end());

	segment_tree<lint> S(n);
	S.update(0,0);
	rep(i,m){
		lint d=S.query(I[i].l,I[i].r);
		S.update(I[i].r-1,d+I[i].wt);
	}

	lint ans=S.query(n-1,n);
	printf("%lld\n",ans<INF?ans:-1);

	return 0;
}
