#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void solve(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	n=a.size();

	int ans=0;
	rep(i,n-1){
		ans=max(ans,a[i+1]-a[i]-1);
	}

	vector<int> b={a[0]-1,k-a.back()};
	rep(i,n-1){
		b.emplace_back((a[i+1]-a[i])/2);
	}
	sort(b.begin(),b.end(),greater<>());
	ans=max(ans,b[0]+b[1]);

	printf("%.9f\n",1.0*ans/k);
}

int main(){
	int q; scanf("%d",&q);
	rep(_,q){
		printf("Case #%d: ",_+1);
		solve();
	}
	return 0;
}
