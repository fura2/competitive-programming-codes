#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

bool dfs(lint x,lint y){
	if(x==0 || y==0) return true;
	if(x%2==1 && y%2==1) return false;
	if(x%2==1) return dfs(x-1,y/2);
	if(y%2==1) return dfs(x/2,y-1);
	return dfs(x-1,y/2) || dfs(x/2,y-1);
}

int main(){
	lint x,y; cin>>x>>y;
	puts(dfs(x,y)?"Yes":"No");
/*
	bool vis[50][50]={};
	vis[0][0]=true;
	queue<pair<int,int>> Q; Q.emplace(0,0);
	while(!Q.empty()){
		int y,x; tie(y,x)=Q.front(); Q.pop();
		if(y+1<50 && 2*x<50 && !vis[y+1][2*x]) vis[y+1][2*x]=true, Q.emplace(y+1,2*x);
		if(2*y<50 && x+1<50 && !vis[2*y][x+1]) vis[2*y][x+1]=true, Q.emplace(2*y,x+1);
	}
	rep(i,50){
		printf("%2d: ",i);
		rep(j,50) putchar(vis[i][j]?'#':'.');
		puts("");
	}
*/
	return 0;
}
