#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.begin(),a.end());

	int q; scanf("%d",&q);
	rep(_,q){
		int x; scanf("%d",&x);
		int i=lower_bound(a.begin(),a.end(),x)-a.begin();
		int ans=1e9;
		if(i<n) ans=min(ans,a[i]-x);
		if(i>0) ans=min(ans,x-a[i-1]);
		printf("%d\n",ans);
	}

	return 0;
}
