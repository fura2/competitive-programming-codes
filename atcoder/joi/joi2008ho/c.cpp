#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> b={0};
	rep(i,n) b.emplace_back(a[i]);
	rep(i,n) rep(j,n) b.emplace_back(a[i]+a[j]);

	sort(b.begin(),b.end());

	int ans=0;
	rep(i,b.size()){
		int idx=upper_bound(b.begin(),b.end(),m-b[i])-b.begin();
		if(idx>0) ans=max(ans,b[i]+b[idx-1]);
	}
	printf("%d\n",ans);

	return 0;
}
