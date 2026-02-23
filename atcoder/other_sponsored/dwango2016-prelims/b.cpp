#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n-1);
	rep(i,n-1) scanf("%d",&a[i]);

	printf("%d ",a[0]);
	rep(i,n-2) printf("%d ",min(a[i],a[i+1]));
	printf("%d\n",a[n-2]);

	return 0;
}
