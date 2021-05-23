#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

double f(double a,double b,double c){
	double theta_b=acos((a*a+c*c-b*b)/(2*a*c));
	double theta_c=acos((a*a+b*b-c*c)/(2*a*b));
	return a/(2+1/tan(theta_b/2)+1/tan(theta_c/2));
}

int main(){
	double x[3],y[3];
	rep(i,3) scanf("%lf%lf",&x[i],&y[i]);

	double a[3];
	rep(i,3) a[i]=hypot(x[i]-x[(i+1)%3],y[i]-y[(i+1)%3]);

	double ans=0;
	rep(i,3) ans=max(ans,f(a[i],a[(i+1)%3],a[(i+2)%3]));
	printf("%.15f\n",ans);

	return 0;
}
