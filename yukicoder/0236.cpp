#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	double a,b,x,y; scanf("%lf%lf%lf%lf",&a,&b,&x,&y);
	if(a/b<x/y) printf("%.9f\n",(1+a/b)*y);
	else        printf("%.9f\n",(1+b/a)*x);
	return 0;
}
