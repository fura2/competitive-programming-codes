#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int h,w; scanf("%d%d",&h,&w);
	vector<lint> a(h-1),b(w),c(h),d(w-1);

	rep(i,h-1) scanf("%lld",&a[i]);
	rep(j, w ) scanf("%lld",&b[j]);
	rep(i, h ) scanf("%lld",&c[i]);
	rep(j,w-1) scanf("%lld",&d[j]);

	vector<lint> y(h-1);
	{
		vector<int> p(h-1);
		iota(p.begin(),p.end(),1);
		sort(p.begin(),p.end(),[&](int i1,int i2){
			return a[i1-1]-c[i1]<a[i2-1]-c[i2];
		});

		auto atmp=a,ctmp=c;
		rep(i,h-1) a[i]=atmp[p[i]-1];
		rep(i,h-1) c[i+1]=ctmp[p[i]];
		rep(i,h-1) y[i]=a[i]-c[i+1];
	}

	vector<lint> asum(h),bsum(w+1),csum(h+1),dsum(w);
	rep(i,h-1) asum[i+1]=asum[i]+a[i];
	rep(j, w ) bsum[j+1]=bsum[j]+b[j];
	rep(i, h ) csum[i+1]=csum[i]+c[i];
	rep(j,w-1) dsum[j+1]=dsum[j]+d[j];

	lint ans=asum[h-1]+(h-1)*b[0]+(w-1)*c[0]+dsum[w-1];
	for(int j=1;j<w;j++){
		int idx=upper_bound(y.begin(),y.end(),d[j-1]-b[j])-y.begin();
		ans+=asum[idx]+idx*b[j];
		ans+=csum[h]-csum[idx+1]+(h-1-idx)*d[j-1];
	}
	printf("%lld\n",ans);

	return 0;
}
