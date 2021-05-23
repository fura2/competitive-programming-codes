#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int q; scanf("%d",&q);
	rep(_,q){
		long double a,b; scanf("%Lf%Lf",&a,&b);
		long double c=b*log10(a);
		long double n=floor(c);
		long double d=pow(10.0L,c-n);
		printf("%.0Lf %.0Lf %.0Lf\n",floor(d),floor((d-floor(d))*10),n);
	}

	return 0;
}
