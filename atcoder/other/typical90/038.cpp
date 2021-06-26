#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long TEN[19]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000,1000000000000,10000000000000,100000000000000,1000000000000000,10000000000000000,100000000000000000,1000000000000000000};

int main(){
	lint a,b; scanf("%lld%lld",&a,&b);
	lint g=gcd(a,b);

	if(a/g<=TEN[18]/b){
		printf("%lld\n",a/g*b);
	}
	else{
		puts("Large");
	}

	return 0;
}
