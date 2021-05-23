#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	double x0,y0,z0; scanf("%d%lf%lf%lf",&n,&x0,&y0,&z0);
	vector<double> x(n),y(n),z(n);
	rep(i,n) scanf("%lf%lf%lf",&x[i],&y[i],&z[i]);

	double ans=0;
	rep(i,n) rep(j,i) rep(k,j) {
		double vx=x[j]-x[i];
		double vy=y[j]-y[i];
		double vz=z[j]-z[i];
		double wx=x[k]-x[i];
		double wy=y[k]-y[i];
		double wz=z[k]-z[i];
		double nx=vy*wz-vz*wy;
		double ny=vz*wx-vx*wz;
		double nz=vx*wy-vy*wx;
		double a=nx,b=ny,c=nz,d=-nx*x[i]-ny*y[i]-nz*z[i];
		ans+=abs(a*x0+b*y0+c*z0+d)/sqrt(a*a+b*b+c*c);
	}
	printf("%.15f\n",ans);

	return 0;
}
