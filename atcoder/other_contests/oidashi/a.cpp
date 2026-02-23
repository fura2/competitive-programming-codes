#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};
const int INF=1<<29;

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	int sx,sy,gx,gy;
	rep(i,h) rep(j,w) {
		if(B[i][j]=='S') sx=i, sy=j;
		if(B[i][j]=='G') gx=i, gy=j;
	}

	vector d(2,vector(h,vector(w,INF)));
	rep(t,2){
		int x0,y0;
		if(t==0) x0=sx, y0=sy;
		else     x0=gx, y0=gy;

		d[t][x0][y0]=0;
		queue<pair<int,int>> Q; Q.emplace(x0,y0);
		while(!Q.empty()){
			int x,y; tie(x,y)=Q.front(); Q.pop();
			rep(k,4){
				int x2=x+dx[k],y2=y+dy[k];
				if(0<=x2 && x2<h && 0<=y2 && y2<w && B[x2][y2]!='#' && d[t][x2][y2]==INF){
					d[t][x2][y2]=d[t][x][y]+1;
					Q.emplace(x2,y2);
				}
			}
		}
	}

	int ans=0;
	rep(i,h) rep(j,w) if(B[i][j]=='#') {
		int res1=INF,res2=INF;
		rep(k,4){
			int x=i+dx[k],y=j+dy[k];
			if(0<=x && x<h && 0<=y && y<w && B[x][y]!='#'){
				res1=min(res1,d[0][x][y]);
				res2=min(res2,d[1][x][y]);
			}
		}
		if(res1<INF && res2<INF) ans=max(ans,res1+res2+2);
	}
	printf("%d\n",ans);

	return 0;
}
