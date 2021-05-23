#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a[6];
	rep(i,6) scanf("%d",&a[i]);
	sort(a,a+3);
	sort(a+3,a+6);
	printf("%d\n",abs(a[0]-a[3])+abs(a[1]-a[4])+abs(a[2]-a[5]));
	return 0;
}
