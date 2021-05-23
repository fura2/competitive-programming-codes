#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int h,w,B[90][90];

int dfs(int i,int j){
	B[i][j]=0;
	int res=1;
	rep(k,4){
		int y=i+dy[k],x=j+dx[k];
		if(0<=y && y<h && 0<=x && x<w && B[y][x]==1) res=max(res,dfs(y,x)+1);
	}

	B[i][j]=1;
	return res;
}

int main(){
	cin>>h>>w;
	rep(i,h) rep(j,w) cin>>B[i][j];

	int ans=0;
	rep(i,h) rep(j,w) if(B[i][j]==1) ans=max(ans,dfs(i,j));
	cout<<ans<<endl;

	return 0;
}
