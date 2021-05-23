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
	for(int i=n+100;;i--) if(!is_prime(i)) { printf("%d\n",i); break; }
	return 0;
}
