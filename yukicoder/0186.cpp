#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T>
T xgcd(T a,T b,T& x,T& y){
	if(b==0){ x=1; y=0; return a; }
	T g=xgcd(b,a%b,y,x);
	y-=a/b*x;
	return g;
}

pair<long long,long long> Chinese_remainder(vector<long long> a,vector<long long> b,vector<long long> m){
	int n=a.size();
	assert(n==b.size() && n==m.size());

	long long x=0,M=1;
	rep(i,n){
		a[i]%=m[i]; if(a[i]<0) a[i]+=m[i];
		b[i]%=m[i]; if(b[i]<0) b[i]+=m[i];
		if(a[i]==0){
			if(b[i]!=0) return {-1,-1};
			continue;
		}

		long long p,q,g;
		g=xgcd(a[i],m[i],p,q);
		if(b[i]%g!=0) return {-1,-1};
		m[i]/=g;
		b[i]=(b[i]/g)*p%m[i];

		g=xgcd(M,m[i],p,q);
		if((b[i]-x)%g!=0) return {-1,-1};
		x+=M*((b[i]-x)/g*p%(m[i]/g));
		M*=m[i]/g;
	}
	x%=M; if(x<0) x+=M;
	return {x,M};
}

int main(){
	vector<lint> x(3),y(3);
	rep(i,3) scanf("%lld%lld",&x[i],&y[i]);

	auto [r,M]=Chinese_remainder({1,1,1},x,y);
	if(r==-1) puts("-1");
	else printf("%lld\n",r==0?M:r);

	return 0;
}
