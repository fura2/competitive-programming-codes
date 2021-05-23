#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	double p,q; scanf("%lf%lf",&p,&q);
	p/=100;
	q/=100;
	printf("%.9f\n",100*p*q/(p*q+(1-p)*(1-q)));
	return 0;
}
