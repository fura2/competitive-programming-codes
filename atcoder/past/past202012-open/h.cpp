#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

int main(){
	int h,w,gx,gy; cin>>h>>w>>gx>>gy; gx--; gy--;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	vector vis(h,vector(w,false));
	vis[gx][gy]=true;
	queue<pair<int,int>> Q;
	Q.emplace(gx,gy);
	while(!Q.empty()){
		int x,y; tie(x,y)=Q.front(); Q.pop();
		rep(k,4){
			int x2=x+dx[k],y2=y+dy[k];
			if(0<=x2 && x2<h && 0<=y2 && y2<w && B[x2][y2]!='#' && !vis[x2][y2]){
				if(B[x2][y2]=='<' && k!=0) continue;
				if(B[x2][y2]=='^' && k!=3) continue;
				if(B[x2][y2]=='>' && k!=2) continue;
				if(B[x2][y2]=='v' && k!=1) continue;
				vis[x2][y2]=true;
				Q.emplace(x2,y2);
			}
		}
	}

	rep(i,h){
		rep(j,w) putchar(B[i][j]=='#'?'#':vis[i][j]?'o':'x');
		puts("");
	}

	return 0;
}
