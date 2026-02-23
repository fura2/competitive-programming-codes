#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(m);
	rep(i,m) scanf("%d",&a[i]);

	int ans=0;
	for(int l=0,r=1;r<=m;r++){
		while(l<r && a[r-1]-a[l]>n) l++;
		ans=max(ans,r-l);
	}
	printf("%d\n",ans);

	return 0;
}
