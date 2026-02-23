#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

int main(){
	while(1){
		int w,h,q; scanf("%d%d%d",&w,&h,&q);
		if(w==0 && h==0 && q==0) break;
		vector B(h,vector(w,0));
		rep(i,h) rep(j,w) scanf("%d",&B[i][j]);

		vector vis(h,vector(w,false));
		rep(_,q){
			int x0,y0; scanf("%d%d",&y0,&x0);

			vis[x0][y0]=true;
			queue<pair<int,int>> Q;
			Q.emplace(x0,y0);
			while(!Q.empty()){
				int x,y; tie(x,y)=Q.front(); Q.pop();
				rep(k,4){
					int x2=x+dx[k],y2=y+dy[k];
					if(0<=x2 && x2<h && 0<=y2 && y2<w && B[x][y]>B[x2][y2] && !vis[x2][y2]){
						vis[x2][y2]=true;
						Q.emplace(x2,y2);
					}
				}
			}
		}

		int ans=0;
		rep(i,h) rep(j,w) if(vis[i][j]) ans++;
		printf("%d\n",ans);
	}

	return 0;
}
