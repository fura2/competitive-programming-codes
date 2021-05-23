#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,h; scanf("%d%d",&n,&h);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	rep(i,n) printf("%d%c",a[i]+h,i<n-1?' ':'\n');

	return 0;
}
