#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

void solve(){
	lint a,b,c; scanf("%lld%lld%lld",&a,&b,&c);

	if(a==0){
		if(b==0){
			if(c==0) puts("3");
			else     puts("0");
		}
		else{
			printf("1 %.15f\n",-1.0*c/b);
		}
	}
	else{
		if(b*b%4==0 && b*b/4==a*c){
			printf("1 %.15f\n",-b/(2.0*a));
		}
		else if(b*b/4>=a*c){
			double d=(b/2.0)*(b/2.0)-a*c;
			double sol[2];
			if(b>0){
				sol[0]=(-b/2.0-sqrt(d))/a;
				sol[1]=-c/(b/2.0+sqrt(d));
			}
			else{ // b<0
				sol[0]=-c/(b/2.0-sqrt(d));
				sol[1]=(-b/2.0+sqrt(d))/a;
			}
			sort(sol,sol+2);
			printf("2 %.15f %.15f\n",sol[0],sol[1]);
		}
		else{
			puts("0");
		}
	}
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
