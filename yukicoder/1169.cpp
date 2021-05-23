#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	rep(i,n) rep(j,n) printf("%d%c",(n-j-1+2*(i-n/2+n))%n+1,j<n-1?' ':'\n');
	return 0;
}
