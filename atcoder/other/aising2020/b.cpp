#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int ans=0;
	for(int i=0;i<n;i+=2) if(a[i]%2==1) ans++;
	printf("%d\n",ans);

	return 0;
}
