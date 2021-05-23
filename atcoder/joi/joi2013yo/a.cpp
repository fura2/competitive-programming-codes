#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int l,a,b,c,d; scanf("%d%d%d%d%d",&l,&a,&b,&c,&d);
	printf("%d\n",l-max((a+c-1)/c,(b+d-1)/d));
	return 0;
}
