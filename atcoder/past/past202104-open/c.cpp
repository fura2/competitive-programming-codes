#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<vector<int>> a(n);
	rep(i,n){
		int k; scanf("%d",&k);
		a[i].resize(k);
		rep(j,k) scanf("%d",&a[i][j]), a[i][j]--;
	}
	int p,q; scanf("%d%d",&p,&q);
	vector<int> b(p);
	rep(i,p) scanf("%d",&b[i]), b[i]--;

	int ans=0;
	rep(i,n){
		int cnt=0;
		rep(j,p) if(find(a[i].begin(),a[i].end(),b[j])!=a[i].end()) cnt++;
		if(cnt>=q) ans++;
	}
	printf("%d\n",ans);

	return 0;
}
