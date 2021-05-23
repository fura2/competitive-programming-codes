#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b; scanf("%lld%lld",&a,&b);

	if(a<0) a*=-1;
	if(b<0) b*=-1;

	if(a==0 && b==0){
		puts("0.25");
		return 0;
	}

	lint g=gcd(a,b);
	a/=g;
	b/=g;

	double ans=0;
	rep(i,20) rep(j,20) {
		if((a+b)%2==1 || (i+j)%2==0){
			double x=1+i*g;
			double y=1+j*g;
			ans+=1.0/pow(x+y,x+y);
		}
	}
	printf("%.15f\n",ans);

	return 0;
}
