#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> x(n);
	rep(i,n) scanf("%d",&x[i]);

	sort(x.begin(),x.end());
	x.erase(unique(x.begin(),x.end()),x.end());

	n=x.size();
	if(n==1) return puts("0"),0;

	int ans=1e6;
	rep(i,n-1) ans=min(ans,x[i+1]-x[i]);
	printf("%d\n",ans);

	return 0;
}
