#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k;
	lint p; scanf("%d%lld%d",&n,&p,&k);

	vector A(n,vector(n,0LL));
	rep(i,n) rep(j,n) scanf("%lld",&A[i][j]);

	auto f=[&](lint x){
		auto d=A;
		rep(i,n) rep(j,n) if(d[i][j]==-1) d[i][j]=x;
		rep(k,n) rep(i,n) rep(j,n) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		int cnt=0;
		rep(i,n) for(int j=i+1;j<n;j++) if(d[i][j]<=p) cnt++;
		return cnt;
	};

	if(f(p+1)==k){
		puts("Infinity");
		return 0;
	}
	if(f(1)<k || k<f(p+1)){
		puts("0");
		return 0;
	}

	lint R;
	lint lo=1,hi=p+1;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;
		if(f(mi)>=k) lo=mi;
		else         hi=mi;
	}
	R=lo;

	lint L;
	lo=0,hi=p+1;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;
		if(f(mi)>k) lo=mi;
		else        hi=mi;
	}
	L=lo;

	printf("%lld\n",R-L);

	return 0;
}
