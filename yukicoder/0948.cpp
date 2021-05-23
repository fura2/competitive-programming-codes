#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double PI=acos(-1);

int main(){
	double r,R; scanf("%lf%lf",&r,&R);
	double theta=2*PI-2*asin(r/R);
	printf("%.9f\n%.9f\n",theta,PI*((R+r)*(R+r)-(R-r)*(R-r))*theta/(2*PI)+PI*r*r);

	return 0;
}
