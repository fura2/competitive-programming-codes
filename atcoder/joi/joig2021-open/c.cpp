#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> cum(n+1);
	rep(i,n) cum[i+1]=cum[i]+a[i];

	int ans=n;
	rep(i,n+1){
		ans=min(ans,(i-cum[i])+(cum[n]-cum[i]));
	}
	printf("%d\n",ans);

	return 0;
}
