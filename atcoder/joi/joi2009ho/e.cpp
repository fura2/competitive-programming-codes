#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

vector<pair<int,int>> solve(){
	int h,w,y0,x0; scanf("%d%d%d%d",&w,&h,&x0,&y0); x0--; y0--;
	int B[500][500];
	rep(i,h) rep(j,w) scanf("%d",&B[i][j]);

	vector<pair<int,int>> res={{0,0}};
	bool vis[500][500]={};
	vis[y0][x0]=true;
	priority_queue<tuple<int,int,int>> Q;
	Q.emplace(-1,y0,x0);

	while(!Q.empty()){
		auto [lev,y,x]=Q.top(); Q.pop();
		lev*=-1;

		if(lev>res.back().first){
			res.emplace_back(lev,res.back().second);
		}
		res.back().second++;

		rep(k,4){
			int y2=y+dy[k],x2=x+dx[k];
			if(0<=y2 && y2<h && 0<=x2 && x2<w && !vis[y2][x2]){
				vis[y2][x2]=true;
				Q.emplace(-B[y2][x2],y2,x2);
			}
		}
	}
	return res;
}

int main(){
	int r; scanf("%d",&r);
	auto p1=solve();
	auto p2=solve();

	int i2;
	for(i2=0;p1.back().first+p2[i2].first<r;i2++);

	int ans=INF;
	for(int i1=int(p1.size())-1;i1>=0;i1--){
		while(i2<p2.size() && p1[i1].second+p2[i2].second<r) i2++;
		if(i2==p2.size()) break;
		ans=min(ans,p1[i1].first+p2[i2].first);
	}
	printf("%d\n",ans);

	return 0;
}
