#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n),c(n);
	rep(i,n) scanf("%d%d%d",&a[i],&b[i],&c[i]);

	static int dp[1<<16][16][3];
	rep(i,n){
		dp[1<<i][i][0]=c[i];
		dp[1<<i][i][1]=a[i];
		dp[1<<i][i][2]=b[i];
	}
	rep(S,1<<n) rep(i,n) rep(j,3) if(dp[S][i][j]>0) {
		int x,y;
		if     (j==0) tie(x,y)=minmax(a[i],b[i]);
		else if(j==1) tie(x,y)=minmax(b[i],c[i]);
		else          tie(x,y)=minmax(c[i],a[i]);
		rep(i2,n) if((S>>i2&1)==0) rep(j2,3) {
			int x2,y2,z2;
			if     (j2==0) tie(x2,y2)=minmax(a[i2],b[i2]), z2=c[i2];
			else if(j2==1) tie(x2,y2)=minmax(b[i2],c[i2]), z2=a[i2];
			else           tie(x2,y2)=minmax(c[i2],a[i2]), z2=b[i2];
			if(x2<=x && y2<=y) dp[S|1<<i2][i2][j2]=max(dp[S|1<<i2][i2][j2],dp[S][i][j]+z2);
		}
	}

	int ans=0;
	rep(S,1<<n) rep(i,n) rep(j,3) ans=max(ans,dp[S][i][j]);
	printf("%d\n",ans);

	return 0;
}
