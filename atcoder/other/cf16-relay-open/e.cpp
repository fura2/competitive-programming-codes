#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);

	int x=abs(a-c),y=abs(b-d);
	int g=gcd(x,y);
	x/=g; y/=g;

	int res=0;
	printf("%d\n",g*(x+y-1));

	return 0;
}
