#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int main(){
	int h,w,n; cin>>h>>w>>n;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	int sx,sy;
	vector<int> cx(n),cy(n);
	rep(i,h) rep(j,w) {
		if(B[i][j]=='S') sx=j, sy=i;
		if(isdigit(B[i][j])) cx[B[i][j]-'1']=j, cy[B[i][j]-'1']=i;
	}

	auto bfs=[&](int x0,int y0){
		vector d(h,vector(w,-1));
		d[y0][x0]=0;
		queue<pair<int,int>> Q; Q.emplace(y0,x0);
		while(!Q.empty()){
			int y,x; tie(y,x)=Q.front(); Q.pop();
			rep(k,4){
				int y2=y+dy[k],x2=x+dx[k];
				if(0<=y2 && y2<h && 0<=x2 && x2<w && B[y2][x2]!='X' && d[y2][x2]==-1){
					d[y2][x2]=d[y][x]+1;
					Q.emplace(y2,x2);
				}
			}
		}
		return d;
	};

	int ans=0,x=sx,y=sy;
	rep(i,n){
		auto d=bfs(x,y);
		ans+=d[cy[i]][cx[i]];
		x=cx[i];
		y=cy[i];
	}
	printf("%d\n",ans);

	return 0;
}
