#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool dfs(int x,int y,int i){
	if(x==0 && y==0) return true;
	if(i==3) return false;
	for(int dx=-2;dx<=2;dx++) for(int dy=-2;dy<=2;dy++) if(abs(dx)+abs(dy)==3) {
		if(dfs(x+dx,y+dy,i+1)) return true;
	}
	return false;
}

int main(){
	int x,y; cin>>x>>y;
	cout<<(dfs(x,y,0)?"YES":"NO")<<'\n';
	return 0;
}
