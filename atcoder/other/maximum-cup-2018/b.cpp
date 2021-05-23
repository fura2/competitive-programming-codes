#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

int h,w;
char B[15][16];

int memo[15][15][4][16][16];

bool dfs(int i,int j,int k,int a,int b){
	int& res=memo[i][j][k][a][b];
	if(res!=-1) return res;

	if(i==h-2 && j==w-2 && a==0 && b==0){
		return res=true;
	}

	int k2=k;
	if(B[i+dx[k2]][j+dy[k2]]!='#' && dfs(i+dx[k2],j+dy[k2],k2,a,b)) return res=true;
	k2=(k+1)%4;
	if(a>0 && B[i+dx[k2]][j+dy[k2]]!='#' && dfs(i+dx[k2],j+dy[k2],k2,a-1,b)) return res=true;
	k2=(k+3)%4;
	if(b>0 && B[i+dx[k2]][j+dy[k2]]!='#' && dfs(i+dx[k2],j+dy[k2],k2,a,b-1)) return res=true;
	return res=false;
}

int main(){
	int a,b; scanf("%d%d%d%d",&a,&b,&h,&w);
	rep(i,h) scanf("%s",B[i]);

	memset(memo,-1,sizeof memo);
	puts(dfs(1,1,3,a,b)?"Yes":"No");

	return 0;
}
