#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	rep(i,n) rep(j,n-i) printf("%d%s",n,j<n-i-1?"":"\n");
	return 0;
}
