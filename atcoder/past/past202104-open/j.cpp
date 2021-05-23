#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	double c; scanf("%d%lf",&n,&c);
	vector<double> x(n),y(n);
	rep(i,n) scanf("%lf%lf",&x[i],&y[i]);

	double x0=accumulate(x.begin(),x.end(),0.0)/n;

	double ans=0;
	rep(i,n){
		ans+=(x0-x[i])*(x0-x[i])+(c-y[i])*(c-y[i]);
	}
	printf("%.15f\n",ans);

	return 0;
}
