#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<double> x(n),y(n);
	rep(i,n) x[i]=i, scanf("%lf",&y[i]);

	double sx=0,sy=0,sxx=0,sxy=0;
	rep(i,n){
		sx+=x[i];
		sy+=y[i];
		sxx+=x[i]*x[i];
		sxy+=x[i]*y[i];
	}
	double a=(n*sxy-sx*sy)/(n*sxx-sx*sx);
	double b=(sxx*sy-sxy*sx)/(n*sxx-sx*sx);

	double ans=0;
	rep(i,n) ans+=(y[i]-(a*x[i]+b))*(y[i]-(a*x[i]+b));
	printf("%.9f %.9f\n%.9f\n",b,a,ans);

	return 0;
}
