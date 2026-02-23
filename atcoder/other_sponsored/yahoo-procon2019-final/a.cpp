#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

double f(double l,double w){
	if(l<=2*w) return (4*w-l)/3;
	else       return (3*l-4*w)*w*w/(3*(l-w)*(l-w));
}

int main(){
	int h,w,a,b; scanf("%d%d%d%d",&h,&w,&a,&b);
	printf("%.15f\n",f(h,a)*f(w,b));
	return 0;
}
