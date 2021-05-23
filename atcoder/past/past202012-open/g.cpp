#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

int h,w;
char B[4][5];

vector<pair<int,int>> ans,tmp;

bool dfs(int i,int j){
	B[i][j]='.';
	tmp.emplace_back(i,j);

	bool ok=true;
	rep(i,h) rep(j,w) if(B[i][j]=='#') ok=false;
	if(ok) ans=tmp;

	rep(k,4){
		if(ok) break;
		int x=i+dx[k],y=j+dy[k];
		if(0<=x && x<h && 0<=y && y<w && B[x][y]=='#'){
			ok|=dfs(x,y);
		}
	}

	B[i][j]='#';
	tmp.pop_back();

	return ok;
}

int main(){
	scanf("%d%d",&h,&w);
	rep(i,h) scanf("%s",B[i]);

	rep(i,h) rep(j,w) {
		if(B[i][j]=='#' && dfs(i,j)){
			printf("%ld\n",ans.size());
			for(auto [x,y]:ans) printf("%d %d\n",x+1,y+1);
			return 0;
		}
	}

	return 0;
}
