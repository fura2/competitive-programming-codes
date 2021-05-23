#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int main(){
	int h,w,l;
	string s; cin>>h>>w>>l>>s;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	static int dp[101][100][100][4];
	rep(t,l+1) rep(i,h) rep(j,w) rep(k,4) dp[t][i][j][k]=INF;
	rep(i,h) rep(j,w) rep(k,4) dp[0][i][j][k]=0;
	rep(t,l) rep(i,h) rep(j,w) rep(k,4) if(dp[t][i][j][k]<INF) {
		rep(k2,4) if(k2!=k) {
			int y=i,x=j;
			bool ok=false;
			while(1){
				y+=dy[k2];
				x+=dx[k2];
				if(y<0 || h<=y || x<0 || w<=x) break;
				if(B[y][x]==s[t]){
					ok=true;
					break;
				}
			}
			if(ok){
				dp[t+1][y][x][k2]=min(dp[t+1][y][x][k2],dp[t][i][j][k]+abs(y-i)+abs(x-j));
			}
		}
	}

	int ans=INF;
	rep(i,h) rep(j,w) rep(k,4) ans=min(ans,dp[l][i][j][k]);
	printf("%d\n",ans<INF?ans:-1);

	return 0;
}
