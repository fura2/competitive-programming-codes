#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;
const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

int main(){
	int h,w,n;
	string dir; cin>>h>>w>>n>>dir;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	int sx,sy,gx,gy;
	rep(i,h) rep(j,w) {
		if(B[i][j]=='S') sx=i, sy=j, B[i][j]='.';
		if(B[i][j]=='G') gx=i, gy=j, B[i][j]='.';
	}

	int f[128];
	f['R']=0; f['U']=1; f['L']=2; f['D']=3;

	dir=dir+dir;
	vector next(2*n+1,vector(4,2*n));
	for(int i=2*n-1;i>=0;i--){
		rep(k,4) next[i][k]=next[i+1][k];
		next[i][f[dir[i]]]=i;
	}

	vector d(h,vector(w,INF));
	d[sx][sy]=0;
	priority_queue<tuple<lint,int,int>> Q; Q.emplace(0,sx,sy);
	while(!Q.empty()){
		lint d0;
		int i,j; tie(d0,i,j)=Q.top(); Q.pop();
		d0*=-1;
		if(d[i][j]<d0) continue;

		int t=d0%n;
		rep(k,4){
			int x=i+dx[k],y=j+dy[k];
			if(0<=x && x<h && 0<=y && y<w && B[x][y]=='.'){
				if(next[t][k]<2*n){
					lint d2=d0+(next[t][k]-t+1);
					if(d2<d[x][y]){
						d[x][y]=d2;
						Q.emplace(-d2,x,y);
					}
				}
			}
		}
	}
	printf("%lld\n",d[gx][gy]<INF?d[gx][gy]:-1);

	return 0;
}
