#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,d; scanf("%d%d",&n,&d);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.rbegin(),a.rend());

	int ans=0;
	for(int i=0;i+d<=n;i+=d) ans+=a[i+d-1];
	printf("%d\n",ans);

	return 0;
}
