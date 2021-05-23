#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	double c,d; cin>>c>>d;

	double ans=0,a,b;
	a=min(4*c/3,4*d);
	b=0;
	ans=max(ans,1000*a+2000*b);

	a=0;
	b=min(7*c/2,7*d/5);
	ans=max(ans,1000*a+2000*b);

	a=(5*c/7-2*d/7)*28/13;
	b=( -c/4+3*d/4)*28/13;
	if(a>=0 && b>=0) ans=max(ans,1000*a+2000*b);

	printf("%.9f\n",ans);

	return 0;
}
