#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

/*
	Hurwitz zeta
		ζ(s,q) = Sum_{n=0}^∞ 1/(q+n)^s
			   = (1/Γ(s)) ∫_0^∞ t^{s-1}exp(-qt)/(1-exp(-t))dt
*/

double q;

double f(double x){
	if(x==0) return 1;
	else     return x*exp(-q*x)/(1-exp(-x));
}

int main(){
	scanf("%lf",&q);
	q++;

	double res=0;
	int N=1e6;
	double L=1e2;
	rep(i,N+1){
		double w;
		if(i==0 || i==N) w=1;
		else if(i%2==1)  w=4;
		else             w=2;
		res+=w*f(i*L/N);
	}
	res*=L/(3*N);
	printf("%.15f\n",res);

	return 0;
}
