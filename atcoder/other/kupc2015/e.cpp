#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void solve(){
	int h,w; scanf("%d%d",&h,&w);
	if(h>w) swap(h,w);

	auto f=[&](double y){
		double lo=0,hi=w;
		rep(_,50){
			double mi1=(2*lo+hi)/3;
			double mi2=(lo+2*hi)/3;

			double tmp1=min(hypot(mi1,h),hypot(w-mi1,h-y));
			double tmp2=min(hypot(mi2,h),hypot(w-mi2,h-y));
			if(tmp1>tmp2) hi=mi2;
			else          lo=mi1;
		}
		return lo;
	};

	double lo=0,hi=h;
	rep(_,50){
		double mi1=(2*lo+hi)/3;
		double mi2=(lo+2*hi)/3;

		double y1=mi1,y2=mi2;
		double x1=f(y1),x2=f(y2);
		double tmp1=min({hypot(w,y1),hypot(x1,h),hypot(w-x1,h-y1)});
		double tmp2=min({hypot(w,y2),hypot(x2,h),hypot(w-x2,h-y2)});
		if(tmp1>tmp2) hi=mi2;
		else          lo=mi1;
	}

	double x=f(lo),y=lo;
	printf("%.9f\n",min({hypot(w,y),hypot(x,h),hypot(w-x,h-y)}));
}

int main(){
	int t; scanf("%d",&t); rep(_,t) solve();
	return 0;
}
