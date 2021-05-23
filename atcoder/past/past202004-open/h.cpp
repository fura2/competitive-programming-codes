#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int main(){
	int h,w; scanf("%d%d",&h,&w);
	char B[50][51];
	rep(i,h) scanf("%s",B[i]);

	int d[50][50][11];
	rep(i,h) rep(j,w) rep(k,11) d[i][j][k]=INF;

	queue<tuple<int,int,int>> Q;
	rep(i,h) rep(j,w) if(B[i][j]=='S') {
		d[i][j][0]=0;
		Q.emplace(i,j,0);
	}
	while(!Q.empty()){
		int i,j,k; tie(i,j,k)=Q.front(); Q.pop();

		if(B[i][j]=='G' && k==10){
			printf("%d\n",d[i][j][k]);
			return 0;
		}

		rep(l,4){
			int y=i+dy[l],x=j+dx[l];
			if(0<=y && y<h && 0<=x && x<w){
				int k2=k;
				if((k<9 && B[y][x]=='0'+k+1) || (k==9 && B[y][x]=='G')) k2++;
				if(d[y][x][k2]==INF){
					d[y][x][k2]=d[i][j][k]+1;
					Q.emplace(y,x,k2);
				}
			}
		}
	}
	puts("-1");

	return 0;
}
