#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.rbegin(),a.rend());

	int ans=0;
	rep(i,k) if(i==0 || a[i]>0) ans+=a[i];
	printf("%d\n",ans);

	return 0;
}
