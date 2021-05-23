#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n+m);
	rep(i,n+m) scanf("%d",&a[i]);
	sort(a.begin(),a.end());
	rep(i,n+m) printf("%d\n",a[i]);
	return 0;
}
