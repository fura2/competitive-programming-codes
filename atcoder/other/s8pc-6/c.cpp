#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h){
		string s; cin>>s;
		rep(_,2*h) B[i]+=s;
	}
	w*=2*h;

	vector vis(h,vector(w,false));
	vis[0][0]=true;
	rep(i,h) rep(j,w) if(vis[i][j]) {
		if(i<h-1 && B[i+1][j]=='.') vis[i+1][j]=true;
		if(j<w-1 && B[i][j+1]=='.') vis[i][j+1]=true;
	}
	puts(vis[h-1][w-1]?"Yay!":":(");

	return 0;
}
