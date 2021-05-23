#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int h,w;
	lint k,v; scanf("%d%d%lld%lld",&h,&w,&k,&v);
	lint a[125][125];
	rep(i,h) rep(j,w) scanf("%lld",&a[i][j]);

	lint sum[126][126]={};
	rep(i,h) rep(j,w) sum[i+1][j+1]=sum[i+1][j]+sum[i][j+1]-sum[i][j]+a[i][j];

	int ans=0;
	rep(y1,h) rep(x1,w) for(int y2=y1+1;y2<=h;y2++) for(int x2=x1+1;x2<=w;x2++) {
		lint cost=sum[y2][x2]-sum[y2][x1]-sum[y1][x2]+sum[y1][x1]+k*(y2-y1)*(x2-x1);
		if(cost<=v) ans=max(ans,(y2-y1)*(x2-x1));
	}
	printf("%d\n",ans);

	return 0;
}
