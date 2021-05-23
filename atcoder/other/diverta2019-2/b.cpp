#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> x(n),y(n);
	rep(i,n) scanf("%d%d",&x[i],&y[i]);

	int ans=n;
	rep(i,n) rep(j,n) if(i!=j) {
		int p=x[j]-x[i],q=y[j]-y[i];
		int cnt=0;
		rep(k,n) rep(l,n) if(k!=l) if(x[k]+p==x[l] && y[k]+q==y[l]) cnt++;
		ans=min(ans,n-cnt);
	}
	printf("%d\n",ans);

	return 0;
}
