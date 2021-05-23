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

/*
	w * h の二次元トーラス上で, (sx, sy) からスタートして
	(dx, dy) 先にジャンプすることを d 回繰り返す間に (gx, gy) にたどり着けるか?
*/
bool solve(lint w,lint h,lint d,lint sx,lint sy,lint gx,lint gy,lint dx,lint dy){
	if(sx!=0 || sy!=0){
		return solve(w,h,d,0,0,(gx-sx+w)%w,(gy-sy+h)%h,dx,dy);
	}

	auto [r,M]=Chinese_remainder({dx,dy},{gx,gy},{w,h});
	return r!=-1 && r<=d;
}

int main(){
	int q; cin>>q;
	rep(_,q){
		lint w,h,d,sx,sy,gx,gy,vx,vy;
		cin>>w>>h>>d>>gx>>gy>>sx>>sy>>vx>>vy;

		lint g=gcd(abs(vx),abs(vy));
		d*=g;
		lint dx=(vx/g)%(2*w); if(dx<0) dx+=2*w;
		lint dy=(vy/g)%(2*h); if(dy<0) dy+=2*h;

		if(solve(2*w,2*h,d,sx,sy,gx,gy,dx,dy)
		|| solve(2*w,2*h,d,sx,sy,(2*w-gx)%(2*w),gy,dx,dy)
		|| solve(2*w,2*h,d,sx,sy,gx,(2*h-gy)%(2*h),dx,dy)
		|| solve(2*w,2*h,d,sx,sy,(2*w-gx)%(2*w),(2*h-gy)%(2*h),dx,dy)) puts("Hit");
		else puts("Miss");
	}

	return 0;
}
