#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int ans=0;
	rep(i,n-2) if(a[i]!=a[i+1] && a[i]!=a[i+2] && a[i+1]!=a[i+2]) {
		int mx=max({a[i],a[i+1],a[i+2]});
		int mn=min({a[i],a[i+1],a[i+2]});
		if((a[i]!=mx && a[i]!=mn) || (a[i+2]!=mx && a[i+2]!=mn)) ans++;
	}
	printf("%d\n",ans);

	return 0;
}
