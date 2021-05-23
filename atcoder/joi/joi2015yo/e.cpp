#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,-1,-1,-1,0,1,1,1};

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h){
		cin>>B[i];
		for(char& c:B[i]) if(c=='.') c='0';
	}

	vector<vector<int>> d(h,vector<int>(w,-1));
	queue<pair<int,int>> Q;
	rep(i,h) rep(j,w) if(B[i][j]=='0') {
		d[i][j]=0;
		Q.emplace(i,j);
	}

	while(!Q.empty()){
		int y,x; tie(y,x)=Q.front(); Q.pop();

		rep(k,8){
			int yy=y+dy[k],xx=x+dx[k];
			if(0<=yy && yy<h && 0<=xx && xx<w && d[yy][xx]==-1){
				B[yy][xx]--;
				if(B[yy][xx]=='0'){
					d[yy][xx]=d[y][x]+1;
					Q.emplace(yy,xx);
				}
			}
		}
	}

	int ans=0;
	rep(i,h) rep(j,w) ans=max(ans,d[i][j]);
	printf("%d\n",ans);

	return 0;
}
