#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.begin(),a.end());

	int ans=0;
	rep(i,n) ans+=abs(i+1-a[i]);
	printf("%d\n",ans);

	return 0;
}
