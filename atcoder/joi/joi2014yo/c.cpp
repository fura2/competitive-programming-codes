#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%*d%*d%d",&n);
	vector<int> x(n),y(n);
	rep(i,n) scanf("%d%d",&x[i],&y[i]);

	int ans=0;
	rep(i,n-1){
		int dx=x[i+1]-x[i],dy=y[i+1]-y[i];
		if(dx*dy>=0) ans+=max(abs(dx),abs(dy));
		else         ans+=abs(dx)+abs(dy);
	}
	printf("%d\n",ans);

	return 0;
}
