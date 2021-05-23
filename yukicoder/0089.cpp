#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double PI=acos(-1);

int main(){
	double c,r,R; scanf("%lf%lf%lf",&c,&r,&R);
	printf("%.9f\n",c*PI*PI*(R-r)*(R-r)*(R+r)/4);
	return 0;
}
