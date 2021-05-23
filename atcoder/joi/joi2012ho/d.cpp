#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);

	static int cum1[5002][5002];
	static int cum2[5002][5002];
	static int cum3[5002][5002];
	rep(i,m){
		int a,b,x; scanf("%d%d%d",&a,&b,&x); a--; b--;
		cum1[a][b]++;
		cum1[a+x+1][b]--;
		cum2[a+x+1][b+1]--;
		cum2[a+x+1][b+x+2]++;
	}
	rep(y,n+1) rep(x,n+2) cum1[y+1][x]+=cum1[y][x];
	rep(y,n+2) rep(x,n+1) cum2[y][x+1]+=cum2[y][x];

	rep(y,n+2) rep(x,n+2) cum3[y][x]=cum1[y][x]+cum2[y][x];
	rep(y,n+1) rep(d,n+1-y) cum3[y+d+1][d+1]+=cum3[y+d][d];

	int ans=0;
	rep(i,n+2) rep(j,n+2) if(cum3[i][j]>0) ans++;
	printf("%d\n",ans);

	return 0;
}
