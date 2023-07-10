#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> ans(n+1);
	for(int x=1;x*x<=n;x++) for(int y=1;y*y<=n;y++) for(int z=1;z*z<=n;z++) {
		int r=x*x+y*y+z*z+x*y+y*z+z*x;
		if(r<=n) ans[r]++;
	}
	rep(i,n) printf("%d\n",ans[i+1]);
	return 0;
}
