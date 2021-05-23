#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int g=0;
	rep(i,n) g=gcd(g,a[i]);

	int ans=0;
	rep(i,n) ans+=a[i]/g;
	printf("%d\n",ans);

	return 0;
}
