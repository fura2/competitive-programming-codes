#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};
const int INF=1<<29;

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	int sx,sy,gx,gy;
	vector<int> X,Y;
	rep(i,h) rep(j,w) {
		if(B[i][j]=='#') continue;
		if(B[i][j]=='@') sx=i, sy=j;
		if(B[i][j]=='%') gx=i, gy=j;
		if(B[i][j]=='$') X.emplace_back(i), Y.emplace_back(j);
		B[i][j]='.';
	}

	vector d(h,vector(w,INF));
	queue<pair<int,int>> Q;
	rep(i,X.size()){
		d[X[i]][Y[i]]=0;
		Q.emplace(X[i],Y[i]);
	}
	while(!Q.empty()){
		int x,y; tie(x,y)=Q.front(); Q.pop();
		rep(k,4){
			int x2=x+dx[k],y2=y+dy[k];
			if(0<=x2 && x2<h && 0<=y2 && y2<w && B[x2][y2]=='.' && d[x2][y2]==INF){
				d[x2][y2]=d[x][y]+1;
				Q.emplace(x2,y2);
			}
		}
	}

	vector d2(h,vector(w,INF));
	d2[sx][sy]=0;
	Q.emplace(sx,sy);
	while(!Q.empty()){
		int x,y; tie(x,y)=Q.front(); Q.pop();
		rep(k,4){
			int x2=x+dx[k],y2=y+dy[k];
			if(0<=x2 && x2<h && 0<=y2 && y2<w && B[x2][y2]=='.' && d2[x2][y2]==INF && d2[x][y]+1<d[x2][y2]){
				d2[x2][y2]=d2[x][y]+1;
				Q.emplace(x2,y2);
			}
		}
	}
	puts(d2[gx][gy]<INF?"Yes":"No");

	return 0;
}
