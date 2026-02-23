#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; scanf("%d%d",&h,&w);
	vector a(h,vector(w,0));
	rep(i,h) rep(j,w) scanf("%d",&a[i][j]);

	vector<int> r(h),c(w);
	rep(i,h) rep(j,w) {
		r[i]+=a[i][j];
		c[j]+=a[i][j];
	}

	rep(i,h) rep(j,w) printf("%d%c",r[i]+c[j]-a[i][j],j<w-1?' ':'\n');

	return 0;
}
