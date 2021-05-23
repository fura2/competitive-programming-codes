#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a[6];
	rep(i,6) scanf("%d",&a[i]);
	printf("%d\n",accumulate(a,a+6,0)-min({a[0],a[1],a[2],a[3]})-min(a[4],a[5]));
	return 0;
}
