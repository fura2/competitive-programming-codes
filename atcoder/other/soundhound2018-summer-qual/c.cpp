#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,d; scanf("%d%d%d",&n,&m,&d);

	double e;
	if(d>0) e=2*(n-d);
	else    e=n;
	e/=n;
	e/=n;
	e*=m-1;
	printf("%.9f\n",e);

	return 0;
}
