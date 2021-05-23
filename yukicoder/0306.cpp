#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int xa,ya,xb,yb; scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
	printf("%.9f\n",ya+1.0*xa/(xa+xb)*(yb-ya));
	return 0;
}
