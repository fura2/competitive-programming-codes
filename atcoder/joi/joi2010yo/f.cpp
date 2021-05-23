#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int h,w,B[10][10],sx,sy;

int dfs(int i,int j,int m){
	if(m==0) return i==sy||j==sx?1:0;

	int res=0;
	rep(k,4){
		int y=i,x=j;
		while(0<=y && y<h && 0<=x && x<w){
			if(B[y][x]==1){
				B[y][x]=0;
				res+=dfs(y,x,m-1);
				B[y][x]=1;
				break;
			}
			y+=dy[k];
			x+=dx[k];
		}
	}
	return res;
}

int main(){
	scanf("%d%d",&w,&h);
	rep(i,h) rep(j,w) scanf("%d",&B[i][j]);

	int m=0;
	rep(i,h) rep(j,w) {
		if(B[i][j]==1) m++;
		if(B[i][j]==2) sy=i, sx=j;
	}

	printf("%d\n",dfs(sy,sx,m));

	return 0;
}
