#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int h,w,q; scanf("%d%d%d",&h,&w,&q);
	vector<int> a(h),b(w);
	rep(i,h) scanf("%d",&a[i]);
	rep(j,w) scanf("%d",&b[j]);

	vector<lint> cumx1(h+1),cumy1(w+1),cumx2(h+1),cumy2(w+1);
	rep(i,h){
		cumx1[i+1]=cumx1[i]+(i%2==0?a[i]:0);
		cumx2[i+1]=cumx2[i]+(i%2==1?a[i]:0);
	}
	rep(j,w){
		cumy1[j+1]=cumy1[j]+(j%2==0?b[j]:0);
		cumy2[j+1]=cumy2[j]+(j%2==1?b[j]:0);
	}

	rep(_,q){
		int px,py,qx,qy; scanf("%d%d%d%d",&px,&py,&qx,&qy); px--; py--;
		lint black=0;
		black+=(cumx1[qx]-cumx1[px])*(cumy1[qy]-cumy1[py]);
		black+=(cumx2[qx]-cumx2[px])*(cumy2[qy]-cumy2[py]);
		lint total=(cumx1[qx]+cumx2[qx]-cumx1[px]-cumx2[px])*(cumy1[qy]+cumy2[qy]-cumy1[py]-cumy2[py]);
		printf("%lld\n",2*black-total);
	}

	return 0;
}
