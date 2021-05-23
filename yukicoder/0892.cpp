#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a[3];
	rep(i,3) scanf("%d%*d",&a[i]);
	puts((a[0]+a[1]+a[2])%2==0?":-)":":-(");
	return 0;
}
