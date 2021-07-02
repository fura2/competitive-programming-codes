#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d%d",&a[i],&b[i]);

	int m=5001;
	vector cum(m+1,vector(m+1,0));
	rep(i,n) cum[a[i]][b[i]]++;
	rep(i,m) rep(j,m) cum[i+1][j+1]+=cum[i+1][j]+cum[i][j+1]-cum[i][j];

	int ans=0;
	rep(i,m-k) rep(j,m-k) {
		ans=max(ans,cum[i+k+1][j+k+1]-cum[i+k+1][j]-cum[i][j+k+1]+cum[i][j]);
	}
	printf("%d\n",ans);

	return 0;
}
