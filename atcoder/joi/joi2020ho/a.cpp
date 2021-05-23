#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n+1),b(n);
	rep(i,n+1) scanf("%d",&a[i]);
	rep(i, n ) scanf("%d",&b[i]);

	vector<pair<int,int>> p(n+1);
	rep(i,n+1) p[i]={a[i],i};

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(p.begin(),p.end());

	vector<int> mx1(n+1),mx2(n+1);
	rep(i,n){
		mx1[i+1]=max(mx1[i],a[i]-b[i]);
	}
	for(int i=n-1;i>=0;i--){
		mx2[i]=max(mx2[i+1],a[i+1]-b[i]);
	}

	vector<int> ans(n+1);
	rep(i,n+1) ans[p[i].second]=max(mx1[i],mx2[i]);
	rep(i,n+1) printf("%d%c",ans[i],i<n?' ':'\n');

	return 0;
}
