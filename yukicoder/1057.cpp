#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; scanf("%d%d",&a,&b);
	printf("%d\n",a==b?a+b-1:2*min(a,b));
	return 0;
}