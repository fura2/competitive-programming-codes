#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	if(n<5) return puts("0"),0;

	double res=1;
	rep(i,n-5) res*=(94.0-i)/(n-5-i);
	rep(i, n ) res/=(99.0-i)/(n-i);
	printf("%.9f\n",12*res);

	return 0;
}
