#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	double a,c,d,e,f;
	scanf("%lf%*lf%lf%lf%lf%lf",&a,&c,&d,&e,&f);
	printf("%.15f\n",sqrt((f-e+c*c/(4*a)+d*d/(4*a))/a));
	return 0;
}
