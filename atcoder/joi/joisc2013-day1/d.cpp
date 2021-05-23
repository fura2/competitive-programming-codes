#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double EPS=1e-8;

int main(){
	int n,w,h; scanf("%d%d%d",&n,&w,&h);
	vector<int> x(n),y(n);
	rep(i,n) scanf("%d%d",&x[i],&y[i]);

	int ans=0;
	rep(i,n) rep(j,n) if(i!=j) {
		int r2=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
		int a=min({x[i],w-x[i],y[i],h-y[i]});
		if(r2>a*a) continue;

		rep(k,n) if(k!=i && k!=j) rep(l,n) if(l!=i && l!=j && l!=k) {
			double rik=hypot(x[i]-x[k],y[i]-y[k]);
			double rkl=hypot(x[k]-x[l],y[k]-y[l]);
			if(rik+rkl<sqrt(r2)-EPS) ans++;
		}
	}
	printf("%d\n",ans);

	return 0;
}
