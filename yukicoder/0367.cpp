#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	int d[500][500][2];
	memset(d,-1,sizeof d);
	queue<tuple<int,int,int>> Q;
	rep(i,h) rep(j,w) if(B[i][j]=='S') {
		d[i][j][0]=0;
		Q.emplace(i,j,0);
	}
	while(!Q.empty()){
		int i,j,t;
		tie(i,j,t)=Q.front(); Q.pop();

		if(B[i][j]=='G') return printf("%d\n",d[i][j][t]),0;

		if(t==0){
			for(int dy=-2;dy<=2;dy++) for(int dx=-2;dx<=2;dx++) if(abs(dx)+abs(dy)==3) {
				int y=i+dy,x=j+dx;
				if(0<=y && y<h && 0<=x && x<w){
					int t2=(B[y][x]=='R'?1-t:t);
					if(d[y][x][t2]==-1){
						d[y][x][t2]=d[i][j][t]+1;
						Q.emplace(y,x,t2);
					}
				}
			}
		}
		else{
			for(int dy=-1;dy<=1;dy+=2) for(int dx=-1;dx<=1;dx+=2) {
				int y=i+dy,x=j+dx;
				if(0<=y && y<h && 0<=x && x<w){
					int t2=(B[y][x]=='R'?1-t:t);
					if(d[y][x][t2]==-1){
						d[y][x][t2]=d[i][j][t]+1;
						Q.emplace(y,x,t2);
					}
				}
			}
		}
	}

	puts("-1");

	return 0;
}
