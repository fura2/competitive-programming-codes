#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

int main(){
	int h,w,sx,sy; cin>>h>>w>>sx>>sy, sx--, sy--;
	vector B(h,vector(w,0));
	rep(i,h) rep(j,w) cin>>B[i][j];

	vector<string> ans(h,string(w,'.'));
	int x=sx,y=sy;
	while(1){
		ans[x][y]='W';
		int next=-1;
		rep(k,4){
			int x2=x+dx[k],y2=y+dy[k];
			if(0<=x2 && x2<h && 0<=y2 && y2<w && B[x2][y2]<B[x][y]){
				if(next==-1 || B[x2][y2]<B[x+dx[next]][y+dy[next]]){
					next=k;
				}
			}
		}
		if(next==-1) break;
		x+=dx[next];
		y+=dy[next];
	}
	rep(i,h) cout<<ans[i]<<'\n';

	return 0;
}
