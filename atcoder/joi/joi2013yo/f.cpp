#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;
const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

int h,w,n;
vector<string> B;

int memo[50][50][4][4][4][4][4][4];

int dfs(int i,int j,int k,int d1,int d2,int d3,int d4,int d5){
	int& res=memo[i][j][k][d1][d2][d3][d4][d5];

	if(res!=-1) return res;

	res=-INF;
	if(i==h-1 && j==w-1) res=0;

	auto f=[&](int d0){
		int i2=i+dx[d0],j2=j+dy[d0];
		bool ok=true;
		int x=i,y=j;
		x-=dx[d1]; y-=dy[d1]; if(x==i2 && y==j2) ok=false;
		x-=dx[d2]; y-=dy[d2]; if(x==i2 && y==j2) ok=false;
		x-=dx[d3]; y-=dy[d3]; if(x==i2 && y==j2) ok=false;
		x-=dx[d4]; y-=dy[d4]; if(x==i2 && y==j2) ok=false;
		x-=dx[d5]; y-=dy[d5]; if(x==i2 && y==j2) ok=false;
		return ok?B[i2][j2]-'0':0;
	};

	// ↓
	if(i<h-1 && B[i+1][j]!='#') res=max(res,dfs(i+1,j,k,3,d1,d2,d3,d4)+f(3));
	// →
	if(j<w-1 && B[i][j+1]!='#') res=max(res,dfs(i,j+1,k,0,d1,d2,d3,d4)+f(0));
	// ↑
	if(i>0 && B[i-1][j]!='#' && k<n) res=max(res,dfs(i-1,j,k+1,1,d1,d2,d3,d4)+f(1));
	// ←
	if(j>0 && B[i][j-1]!='#' && k<n) res=max(res,dfs(i,j-1,k+1,2,d1,d2,d3,d4)+f(2));

	return res;
}

int main(){
	cin>>h>>w>>n;
	B.resize(h);
	rep(i,h){
		cin>>B[i];
		rep(j,w) if(B[i][j]=='.') B[i][j]='0';
	}

	memset(memo,-1,sizeof memo);
	cout<<dfs(0,0,0,0,0,0,0,0)<<'\n';

	return 0;
}
