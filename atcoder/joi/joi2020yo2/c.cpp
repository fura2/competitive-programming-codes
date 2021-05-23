#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int digitsum(int n){
	int res=0;
	while(n>0) res+=n%10, n/=10;
	return res;
}

int main(){
	int n; scanf("%d",&n);

	bool ok[1001000]={};
	ok[n]=true;
	for(int i=n-1;i>0;i--) ok[i]=ok[i+digitsum(i)];

	printf("%ld\n",count(ok,ok+n+1,true));

	return 0;
}
