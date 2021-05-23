#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,l,r; scanf("%d%d%d",&n,&l,&r);

	rep(i,n){
		int a; scanf("%d",&a);
		printf("%d%c",min(max(a,l),r),i<n-1?' ':'\n');
	}

	return 0;
}
