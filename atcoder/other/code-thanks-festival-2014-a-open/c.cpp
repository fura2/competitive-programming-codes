#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int ans=0;
	rep(j,m){
		int k; scanf("%d",&k); k--;
		ans+=a[k];
	}
	printf("%d\n",ans);

	return 0;
}
