#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool is_prime(long long a){
	if(a%2==0) return a==2;
	for(long long i=3;i*i<=a;i+=2) if(a%i==0) return false;
	return a!=1;
}

int main(){
	int n; scanf("%d",&n);
	if(is_prime(n)) puts("Sosu!");
	else if(n>=2 && int(sqrt(n))*int(sqrt(n))==n) puts("Heihosu!");
	else if(n>=2 && int(cbrt(n))*int(cbrt(n))*int(cbrt(n))==n) puts("Ripposu!");
	else if(n==6 || n==28) puts("Kanzensu!");
	else printf("%d\n",n);
	return 0;
}
