#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;
const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

int h,w;
string B[16];

int dfs(int i,int j,int i0,int j0){
	B[i][j]='#';
	int res=-INF;
	rep(k,4){
		int x=i+dx[k],y=j+dy[k];
		if(x==i0 && y==j0){
			res=1;
			continue;
		}
		if(0<=x && x<h && 0<=y && y<w && B[x][y]=='.'){
			res=max(res,1+dfs(x,y,i0,j0));
		}
	}
	B[i][j]='.';
	return res;
}

int main(){
	cin>>h>>w;
	rep(i,h) cin>>B[i];

	int ans=0;
	rep(i,h) rep(j,w) if(B[i][j]=='.') ans=max(ans,dfs(i,j,i,j));
	cout<<(ans<3?-1:ans)<<'\n';

	return 0;
}
