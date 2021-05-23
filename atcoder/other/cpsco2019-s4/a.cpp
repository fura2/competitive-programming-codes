#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int l,x; scanf("%d%d",&l,&x);
	x%=2*l;
	printf("%d\n",x<l?x:2*l-x);
	return 0;
}
