#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[2][6]={{1,0,-1,-1,-1,0},{1,1,0,-1,0,1}},dy[6]={0,-1,-1,0,1,1};

int main(){
	int h,w; scanf("%d%d",&w,&h);
	int B[102][102]={};
	rep(i,h) rep(j,w) scanf("%d",&B[i+1][j+1]);
	h+=2; w+=2;

	int ans=0;
	bool vis[102][102]={};
	vis[0][0]=true;
	queue<pair<int,int>> Q; Q.emplace(0,0);
	while(!Q.empty()){
		int y,x; tie(y,x)=Q.front(); Q.pop();
		rep(k,6){
			int y2=y+dy[k],x2=x+dx[y%2][k];
			if(0<=y2 && y2<h && 0<=x2 && x2<w && !vis[y2][x2]){
				if(B[y2][x2]==1) ans++;
				else{
					vis[y2][x2]=true;
					Q.emplace(y2,x2);
				}
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}
