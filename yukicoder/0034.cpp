#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
const int INF=1<<29;

int main(){
	int n,v,sx,sy,gx,gy,B[100][100];
	scanf("%d%d%d%d%d%d",&n,&v,&sx,&sy,&gx,&gy); sx--; sy--; gx--; gy--;
	rep(i,n) rep(j,n) scanf("%d",&B[i][j]);

	if(v>=1800) return printf("%d\n",abs(sx-gx)+abs(sy-gy)),0;

	static int d[100][100][1800];
	rep(i,n) rep(j,n) rep(k,v+1) d[i][j][k]=INF;
	d[sy][sx][v]=0;
	priority_queue<tuple<int,int,int,int>> Q; Q.emplace(0,sy,sx,v);
	while(!Q.empty()){
		int d0,i,j,k; tie(d0,i,j,k)=Q.top(); Q.pop();
		d0*=-1;
		if(d0>d[i][j][k]) continue;

		if(i==gy && j==gx) return printf("%d\n",d0),0;
		rep(l,4){
			int y=i+dy[l],x=j+dx[l];
			if(0<=y && y<n && 0<=x && x<n && B[y][x]<k && d[y][x][k-B[y][x]]>d0+1){
				d[y][x][k-B[y][x]]=d0+1;
				Q.emplace(-(d0+1),y,x,k-B[y][x]);
			}
		}
	}

	puts("-1");

	return 0;
}
