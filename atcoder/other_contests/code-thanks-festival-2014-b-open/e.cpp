#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int main(){
	int h,w,sy,sx,gy,gx; cin>>h>>w>>sy>>sx>>gy>>gx;
	sy--; sx--; gy--; gx--;

	int n,B[48][48]={}; cin>>n;
	rep(_,n){
		int r,c,a,b; cin>>r>>c>>a>>b; r--; c--;
		for(int i=r;i<r+a;i++) for(int j=c;j<c+b;j++) B[i][j]=1;
	}

	if(B[sy][sx]==0 || B[gy][gx]==0) return puts("NO"),0;

	bool vis[48][48]={};
	vis[sy][sx]=true;
	queue<pair<int,int>> Q; Q.emplace(sy,sx);
	while(!Q.empty()){
		int i,j; tie(i,j)=Q.front(); Q.pop();
		rep(k,4){
			int y=i+dy[k],x=j+dx[k];
			if(0<=y && y<h && 0<=x && x<w && B[y][x]==1 && !vis[y][x]){
				vis[y][x]=true;
				Q.emplace(y,x);
			}
		}
	}
	puts(vis[gy][gx]?"YES":"NO");

	return 0;
}
