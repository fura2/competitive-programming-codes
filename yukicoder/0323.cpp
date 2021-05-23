#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int main(){
	int h,w; scanf("%d%d",&h,&w);
	int sn,sy,sx; scanf("%d%d%d",&sn,&sy,&sx);
	int gn,gy,gx; scanf("%d%d%d",&gn,&gy,&gx);
	char B[50][51];
	rep(i,h) scanf("%s",B[i]);

	static bool vis[50][50][1200];
	vis[sy][sx][sn]=true;
	queue<tuple<int,int,int>> Q; Q.emplace(sy,sx,sn);
	while(!Q.empty()){
		int y,x,n; tie(y,x,n)=Q.front(); Q.pop();
		rep(k,4){
			int yy=y+dy[k],xx=x+dx[k];
			if(0<=yy && yy<h && 0<=xx && xx<w){
				int nn=n+(B[yy][xx]=='*'?1:-1);
				if(0<nn && nn<1200 && !vis[yy][xx][nn]){
					vis[yy][xx][nn]=true;
					Q.emplace(yy,xx,nn);
				}
			}
		}
	}
	puts(vis[gy][gx][gn]?"Yes":"No");

	return 0;
}
