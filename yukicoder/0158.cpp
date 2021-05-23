#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int a[3],b[3],c[3],nb,nc;
	rep(i,3) scanf("%d",&a[i]);
	scanf("%d",&nb);
	rep(i,3) scanf("%d",&b[i]);
	scanf("%d",&nc);
	rep(i,3) scanf("%d",&c[i]);

	static int dp[11][101][10001];
	rep(i,11) rep(j,101) rep(k,10001) dp[i][j][k]=-INF;
	dp[a[0]][a[1]][a[2]]=0;
	for(int total=10000;total>=0;total--){
		for(int i=10;i>=0;i--) for(int j=100;j>=0;j--) {
			int k=total-1000*i-100*j;
			if(k<0 || 10000<k || dp[i][j][k]==-INF) continue;

			int sum,i2,j2,k2;
			sum=nb;
			i2=min(sum/1000,i); sum-=1000*i2;
			j2=min(sum/100,j);  sum-=100*j2;
			k2=min(sum,k);      sum-=k2;
			if(sum==0){
				dp[i-i2+b[0]][j-j2+b[1]][k-k2+b[2]]=max(dp[i-i2+b[0]][j-j2+b[1]][k-k2+b[2]],dp[i][j][k]+1);
			}

			sum=nc;
			i2=min(sum/1000,i); sum-=1000*i2;
			j2=min(sum/100,j);  sum-=100*j2;
			k2=min(sum,k);      sum-=k2;
			if(sum==0){
				dp[i-i2+c[0]][j-j2+c[1]][k-k2+c[2]]=max(dp[i-i2+c[0]][j-j2+c[1]][k-k2+c[2]],dp[i][j][k]+1);
			}
		}
	}

	int ans=0;
	rep(i,11) rep(j,101) rep(k,10001) ans=max(ans,dp[i][j][k]);
	printf("%d\n",ans);

	return 0;
}
