#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a[3],b[3];
	rep(i,3) scanf("%d",&a[i]);
	rep(i,3) scanf("%d",&b[i]);

	int c[3]={2*(a[0]+a[1]),2*(a[0]+a[2]),2*(a[1]+a[2])};

	sort(b,b+3);
	sort(c,c+3);

	printf("%d\n",b[0]*c[2]+b[1]*c[1]+b[2]*c[0]);

	return 0;
}
