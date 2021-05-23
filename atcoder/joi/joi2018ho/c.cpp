#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int h,w;
char B[3000][3001];

int memo[3000][3000][2][2];

int dfs(int i,int j,bool used1,bool used2){
	if(i>=h || j<0) return 0;

	int& res=memo[i][j][used1][used2];
	if(res!=-1) return res;

	res=dfs(i+1,j-1,false,false);
	if(1<=i && i<h-1 && B[i-1][j]=='R' && B[i][j]=='G' && B[i+1][j]=='W' && !used1){
		// (i, j) を中心とした縦 3 つを使う
		res=max(res,dfs(i+1,j-1,false,true)+1);
	}
	if(1<=j && j<w-1 && B[i][j-1]=='R' && B[i][j]=='G' && B[i][j+1]=='W' && !used2){
		// (i, j) を中心とした横 3 つを使う
		res=max(res,dfs(i+1,j-1,true,false)+1);
	}
	return res;
}

int main(){
	scanf("%d%d",&h,&w);
	rep(i,h) scanf("%s",B[i]);

	memset(memo,-1,sizeof memo);

	int ans=0;
	rep(d,w){
		ans+=dfs(0,d,false,false);
	}
	for(int d=1;d<h;d++){
		ans+=dfs(d,w-1,false,false);
	}
	printf("%d\n",ans);

	return 0;
}
