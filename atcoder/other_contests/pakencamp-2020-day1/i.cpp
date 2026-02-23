#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};
const int INF=1<<29;

int main(){
	int h,w; cin>>h>>w;
	int sx,sy,gx,gy; cin>>sx>>sy>>gx>>gy; sx--; sy--; gx--; gy--;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	vector d(h,vector(w,vector(2,INF)));
	queue<tuple<int,int,int>> Q;
	rep(dir,2){
		d[sx][sy][dir]=0;
		Q.emplace(sx,sy,dir);
	}
	while(!Q.empty()){
		int x,y,dir; tie(x,y,dir)=Q.front();
		Q.pop();

		if(x==gx && y==gy){
			printf("%d\n",d[x][y][dir]);
			return 0;
		}

		rep(k,4) if(k%2==dir) {
			int x2=x+dx[k],y2=y+dy[k],dir2=1-dir;
			if(0<=x2 && x2<h && 0<=y2 && y2<w && B[x2][y2]!='#' && d[x2][y2][dir2]==INF){
				d[x2][y2][dir2]=d[x][y][dir]+1;
				Q.emplace(x2,y2,dir2);
			}
		}
	}

	puts("-1");

	return 0;
}
