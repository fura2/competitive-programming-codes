#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int p,q; scanf("%d%d",&p,&q);
	double lo=1,hi=1e18;
	rep(_,100){
		double mi=(lo+hi)/2;
		if(mi*mi>p+q*mi*log2(mi)) hi=mi;
		else                      lo=mi;
	}
	printf("%.9f\n",lo);
	return 0;
}
