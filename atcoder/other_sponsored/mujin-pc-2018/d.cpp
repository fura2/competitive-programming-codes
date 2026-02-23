#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int rev(int x){
	int res=0;
	while(x>0) res=10*res+x%10, x/=10;
	return res;
}

int memo[1000][1000]; // 0: 未訪問, 1: 有限回で終了, 2: 無限ループ, 3: 保留

int dfs(int x,int y){
	if(memo[x][y]!=0) return memo[x][y];

	int& res=memo[x][y];
	res=3;

	if(x==0 || y==0) return res=1;

	if(x<y) x=rev(x);
	else    y=rev(y);
	if(x<y) y-=x;
	else    x-=y;

	if(memo[x][y]==2 || memo[x][y]==3){
		return res=2;
	}
	else{
		return res=dfs(x,y);
	}
}

int main(){
	int n,m; scanf("%d%d",&n,&m);

	int ans=0;
	rep(x,n+1) rep(y,m+1) if(dfs(x,y)==2) ans++;
	printf("%d\n",ans);

	return 0;
}
