#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	int a[4]={1,3,2,4};
	rep(i,n-k) printf("%d%c",a[i%4],i<n-1?' ':'\n');
	rep(i,k) printf("%d%c",a[(n-k-1)%4],i<k-1?' ':'\n');
	return 0;
}
