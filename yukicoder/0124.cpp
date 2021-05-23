#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

bool is_kadomatsu(int a,int b,int c){
	if(a==b || a==c || b==c) return false;
	if(a<b && b>c) return true;
	if(a>b && b<c) return true;
	return false;
}
int main(){
	int h,w; scanf("%d%d",&w,&h);
	int a[100][100];
	rep(i,h) rep(j,w) scanf("%d",&a[i][j]);

	int d[100][100][4];
	rep(i,h) rep(j,w) rep(k,4) d[i][j][k]=-1;
	d[0][1][0]=1;
	d[1][0][3]=1;
	queue<tuple<int,int,int>> Q;
	Q.emplace(0,1,0);
	Q.emplace(1,0,3);
	while(!Q.empty()){
		int y,x,k; tie(y,x,k)=Q.front(); Q.pop();

		if(y==h-1 && x==w-1) return printf("%d\n",d[y][x][k]),0;

		int a0=a[y-dy[k]][x-dx[k]],a1=a[y][x];
		rep(kk,4){
			int yy=y+dy[kk],xx=x+dx[kk];
			if(0<=yy && yy<h && 0<=xx && xx<w && d[yy][xx][kk]==-1){
				int a2=a[yy][xx];
				if(is_kadomatsu(a0,a1,a2)){
					d[yy][xx][kk]=d[y][x][k]+1;
					Q.emplace(yy,xx,kk);
				}
			}
		}
	}
	puts("-1");

	return 0;
}
