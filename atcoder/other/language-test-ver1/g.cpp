#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,1,0,-1,-1,-1,0,1};
const int dy[]={0,-1,-1,-1,0,1,1,1};

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	int ans[3]={};
	vector vis(h,vector(w,false));
	rep(i,h) rep(j,w) if(B[i][j]=='o' && !vis[i][j]) {
		int cnt=0;
		vis[i][j]=true;
		queue<pair<int,int>> Q; Q.emplace(i,j);
		while(!Q.empty()){
			auto [y,x]=Q.front(); Q.pop();
			cnt++;
			rep(k,8){
				int yy=y+dy[k],xx=x+dx[k];
				if(0<=yy && yy<h && 0<=xx && xx<w && B[yy][xx]=='o' && !vis[yy][xx]){
					vis[yy][xx]=true;
					Q.emplace(yy,xx);
				}
			}
		}
		for(int d=2;d*d<=cnt;d++) if(cnt%(d*d)==0) cnt/=d*d, d--;
		if     (cnt==3) ans[0]++;
		else if(cnt==1) ans[1]++;
		else            ans[2]++;
	}
	printf("%d %d %d\n",ans[0],ans[1],ans[2]);

	return 0;
}
