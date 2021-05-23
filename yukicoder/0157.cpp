#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int main(){
	int h,w; scanf("%d%d",&w,&h);
	string B[20];
	rep(i,h) cin>>B[i];

	int i0=-1,j0=-1;
	rep(i,h) rep(j,w) if(i0==-1 && B[i][j]=='.') { i0=i; j0=j; }

	bool ini[20][20]={};
	ini[i0][j0]=true;
	queue<pair<int,int>> Q; Q.emplace(i0,j0);
	while(!Q.empty()){
		int y,x; tie(y,x)=Q.front(); Q.pop();
		rep(k,4){
			int yy=y+dy[k],xx=x+dx[k];
			if(0<=yy && yy<h && 0<=xx && xx<w && B[yy][xx]=='.' && !ini[yy][xx]){
				ini[yy][xx]=true;
				Q.emplace(yy,xx);
			}
		}
	}

	int d[20][20]={};
	rep(y,h) rep(x,w) {
		if(ini[y][x]){
			d[y][x]=0;
			Q.emplace(y,x);
		}
		else{
			d[y][x]=-1;
		}
	}

	while(!Q.empty()){
		int y,x; tie(y,x)=Q.front(); Q.pop();
		rep(k,4){
			int yy=y+dy[k],xx=x+dx[k];
			if(0<=yy && yy<h && 0<=xx && xx<w && d[yy][xx]==-1){
				d[yy][xx]=d[y][x]+1;
				if(B[yy][xx]=='.'){
					printf("%d\n",d[yy][xx]-1);
					return 0;
				}
				Q.emplace(yy,xx);
			}
		}
	}

	return 0;
}
