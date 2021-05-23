#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int h,w;
char B[1000][1001];
vector<pair<int,int>> S; // stamped set

bool is_stamped(int i,int j){
	if(B[i][j]=='#') return true;
	for(auto p:S){
		int y=p.first,x=p.second;
		if(y<=i && i<y+h/2 && x<=j && j<x+w/2) return true;
	}
	return false;
}

int dfs(int dep){
	if(dep==4) return 0;

	bool ok=true;
	int t=h,l=w,b=0,r=0;
	rep(i,h) rep(j,w) if(!is_stamped(i,j)) {
		ok=false;
		t=min(t,i);
		l=min(l,j);
		b=max(b,i+1);
		r=max(r,j+1);
	}
	if(ok) return 0;

	int ans=4;
	rep(i,4){
		if     (i==0) S.emplace_back(t,l);
		else if(i==1) S.emplace_back(t,r-w/2);
		else if(i==2) S.emplace_back(b-h/2,l);
		else          S.emplace_back(b-h/2,r-w/2);
		ans=min(ans,dfs(dep+1)+1);
		S.pop_back();
	}
	return ans;
}

int main(){
	scanf("%d%d",&h,&w);
	rep(i,h) scanf("%s",B[i]);

	printf("%d\n",dfs(0));

	return 0;
}
