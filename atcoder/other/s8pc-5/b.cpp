#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<double> x1(n),y1(n),r1(n),x2(m),y2(m);
	rep(i,n) scanf("%lf%lf%lf",&x1[i],&y1[i],&r1[i]);
	rep(i,m) scanf("%lf%lf",&x2[i],&y2[i]);

	double ans=1e9;
	rep(i,n) ans=min(ans,r1[i]);
	rep(i,n) rep(j,m) ans=min(ans,hypot(x1[i]-x2[j],y1[i]-y2[j])-r1[i]);
	rep(i,m) rep(j,i) ans=min(ans,hypot(x2[i]-x2[j],y2[i]-y2[j])/2);
	printf("%.9f\n",ans);

	return 0;
}
