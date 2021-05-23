#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]), a[i]--;

	int ans=0;
	rep(i,n) if(a[a[i]]==i) ans++;
	printf("%d\n",ans/2);

	return 0;
}
