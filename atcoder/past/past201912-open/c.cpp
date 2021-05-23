#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a[6];
	rep(i,6) scanf("%d",&a[i]);
	sort(a,a+6);
	printf("%d\n",a[3]);
	return 0;
}
