#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n),b(m);
	rep(i,n) scanf("%d",&a[i]);
	rep(j,m) scanf("%d",&b[j]);

	int ans=0;
	rep(i,n) rep(j,m) if(a[i]<=b[j]) ans++;
	printf("%d\n",ans);

	return 0;
}
