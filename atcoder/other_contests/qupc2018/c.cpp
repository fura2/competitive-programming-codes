#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

int main(){
	int h,w,th; cin>>h>>w>>th;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	vector d(h,vector(w,-1));
	queue<pair<int,int>> Q;
	rep(i,h) rep(j,w) if(B[i][j]=='@') {
		d[i][j]=0;
		Q.emplace(i,j);
	}
	while(!Q.empty()){
		int x,y;
		tie(x,y)=Q.front(); Q.pop();
		rep(k,4){
			int x2=x+dx[k],y2=y+dy[k];
			if(0<=x2 && x2<h && 0<=y2 && y2<w && B[x2][y2]!='#' && d[x2][y2]==-1){
				d[x2][y2]=d[x][y]+1;
				Q.emplace(x2,y2);
			}
		}
	}

	rep(i,h) rep(j,w) if(d[i][j]!=-1 && d[i][j]<=th) B[i][j]='#';

	rep(i,h) rep(j,w) d[i][j]=-1;
	rep(i,h) rep(j,w) if(B[i][j]=='S') {
		d[i][j]=0;
		Q.emplace(i,j);
	}
	while(!Q.empty()){
		int x,y;
		tie(x,y)=Q.front(); Q.pop();
		if(B[x][y]=='G'){
			printf("%d\n",d[x][y]);
			return 0;
		}
		rep(k,4){
			int x2=x+dx[k],y2=y+dy[k];
			if(0<=x2 && x2<h && 0<=y2 && y2<w && B[x2][y2]!='#' && d[x2][y2]==-1){
				d[x2][y2]=d[x][y]+1;
				Q.emplace(x2,y2);
			}
		}
	}
	puts("-1");

	return 0;
}
