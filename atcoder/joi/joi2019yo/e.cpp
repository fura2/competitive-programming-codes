#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T>
class segment_tree{
	int n;
	vector<T> dat;

	void update_min(int l,int r,int a,int b,int u,T v){
		if(l<=a && b<=r){ dat[u]=min(dat[u],v); return; }
		int c=(a+b+1)/2;
		if(l<c && a<r) update_min(l,r,a,c,2*u  ,v);
		if(l<b && c<r) update_min(l,r,c,b,2*u+1,v);
	}

public:
	segment_tree(int N,T v){
		for(n=1;n<N;n*=2);
		dat.assign(2*n,v);
	}

	void update_min(int l,int r,T v){ update_min(l,r,0,n,1,v); }

	T query(int u){
		u+=n;
		T res=dat[u];
		for(u/=2;u>=1;u/=2) res=min(res,dat[u]);
		return res;
	}
};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	segment_tree<int> ST(n,n);
	rep(i,m){
		int l,r; scanf("%d%d",&l,&r); l--;
		ST.update_min(l,r,l);
	}

	vector<lint> dp(n+1);
	rep(i,n){
		dp[i+1]=max(dp[i],dp[min(ST.query(i),i)]+a[i]);
	}
	printf("%lld\n",dp[n]);

	return 0;
}
