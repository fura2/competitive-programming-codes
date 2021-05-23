#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,1,0,-1,-1,0},dy[]={0,1,1,1,0,-1};
const int INF=1<<29;

int main(){
	int n,gx,gy; scanf("%d%d%d",&n,&gx,&gy);
	gx+=250;
	gy+=250;
	bool B[500][500]={};
	rep(i,n){
		int x,y; scanf("%d%d",&x,&y);
		B[y+250][x+250]=true;
	}

	int d[500][500];
	rep(i,500) rep(j,500) d[i][j]=INF;
	d[250][250]=0;
	queue<pair<int,int>> Q; Q.emplace(250,250);
	while(!Q.empty()){
		int y,x; tie(y,x)=Q.front(); Q.pop();
		rep(k,6){
			int y2=y+dy[k],x2=x+dx[k];
			if(0<=y2 && y2<500 && 0<=x2 && x2<500 && !B[y2][x2] && d[y2][x2]==INF){
				d[y2][x2]=d[y][x]+1;
				Q.emplace(y2,x2);
			}
		}
	}
	printf("%d\n",d[gy][gx]<INF?d[gy][gx]:-1);

	return 0;
}
