// https://math.stackexchange.com/questions/454583/volume-of-cube-section-above-intersection-with-plane

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,k; scanf("%lld%lld",&n,&k);

	if(k<=n){
		printf("%lld\n",k*k*k);
	}
	else if(k<=2*n){
		printf("%d\n",k*k*k-3*(k-n)*(k-n)*(k-n));
	}
	else if(k<=3*n){
		printf("%lld\n",6*n*n*n-(3*n-k)*(3*n-k)*(3*n-k));
	}
	else{
		printf("%lld\n",6*n*n*n);
	}

	return 0;
}
