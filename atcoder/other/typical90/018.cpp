#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double PI=acos(-1);

int main(){
	double t,l,x,y;
	scanf("%lf%lf%lf%lf",&t,&l,&x,&y);

	int q; scanf("%d",&q);
	rep(_,q){
		double e; scanf("%lf",&e);
		double X=0,Y=-l/2*sin(2*PI*e/t),Z=-l/2*cos(2*PI*e/t)+l/2;
		double theta=atan2(Z,hypot(X-x,Y-y));
		printf("%.9f\n",theta*180/PI);
	}

	return 0;
}
