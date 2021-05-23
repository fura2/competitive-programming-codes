#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; scanf("%d%d",&a,&b);

	if(gcd(a,b)!=1) return puts("-1"),0;

	bool ok[20001]={};
	rep(i,b+1) rep(j,a+1) ok[a*i+b*j]=true;
	printf("%ld\n",count(ok,ok+lcm(a,b)+1,false));

	return 0;
}
