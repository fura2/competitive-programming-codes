#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; cin>>h>>w;
	string B[100];
	rep(i,h) cin>>B[i];

	vector<int> x,y;
	rep(i,h) rep(j,w) if(B[i][j]=='*') {
		x.emplace_back(j);
		y.emplace_back(i);
	}

	int x3,y3;
	if(y[0]==y[1]){
		x3=x[0];
		y3=(y[0]==0?1:0);
	}
	else{
		x3=(x[0]==0?1:0);
		y3=y[0];
	}
	B[y3][x3]='*';

	rep(i,h) cout<<B[i]<<'\n';

	return 0;
}
