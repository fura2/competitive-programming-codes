#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int m; scanf("%d",&m);
	vector<int> x(m),y(m);
	rep(i,m) scanf("%d%d",&x[i],&y[i]);
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d%d",&a[i],&b[i]);

	set<pair<int,int>> S;
	rep(i,n) S.emplace(a[i],b[i]);

	rep(i,n){
		bool ok=true;
		rep(j,m) if(S.count({x[j]+a[i]-x[0],y[j]+b[i]-y[0]})==0) ok=false;
		if(ok){
			printf("%d %d\n",a[i]-x[0],b[i]-y[0]);
			return 0;
		}
	}
	return 0;
}
