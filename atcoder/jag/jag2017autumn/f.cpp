#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	rep(j,w) if(B[0][j]=='.') B[0][j]='#';
	rep(i,h) rep(j,w) if(B[i][j]=='.') {
		if(i==0
		|| j==0 || j==w-1
		|| (i>=2 && j%2==0)
		|| (i==2 && j%4!=1)
		|| (i==h-1 && j%4!=3)){
			B[i][j]='#';
		}
	}

	int x0=-1,y0;
	rep(i,h) rep(j,w) if(B[i][j]=='@') {
		rep(k,4){
			int x=i+dx[k],y=j+dy[k];
			if(0<=x && x<h && 0<=y && y<w && B[x][y]=='#'){
				x0=x;
				y0=y;
				break;
			}
		}
	}
	assert(x0!=-1);

	while(1){
		B[x0][y0]='.';
		bool nxt=false;
		rep(k,4){
			int x=x0+dx[k],y=y0+dy[k];
			if(0<=x && x<h && 0<=y && y<w && B[x][y]=='#'){
				x0=x;
				y0=y;
				nxt=true;
				break;
			}
		}
		if(!nxt) break;
	}

	rep(i,h) cout<<B[i]<<'\n';

	return 0;
}
