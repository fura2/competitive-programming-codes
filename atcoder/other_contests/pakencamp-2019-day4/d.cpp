#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,x; scanf("%d%d",&n,&x);

	int k=0;
	while(k*(k+1)/2<x) k++;

	int a[1000]={};
	fill(a+k,a+n,2);

	int r=k*(k+1)/2-x;
	if(r>0) a[r-1]=a[k-1]=1;

	puts("1");
	rep(i,n) printf("%d%c",a[i],i<n-1?' ':'\n');

	return 0;
}
