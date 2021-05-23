#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	for(int k=1;k<=m;k++) rep(i,n-1) if(a[i]%k>a[i+1]%k) swap(a[i],a[i+1]);

	rep(i,n) printf("%d\n",a[i]);

	return 0;
}
