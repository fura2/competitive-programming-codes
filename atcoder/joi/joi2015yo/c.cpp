#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	rep(i,h) rep(j,w) {
		int res=INF;
		rep(x,j+1) if(B[i][x]=='c') res=min(res,j-x);
		printf("%d%c",res<INF?res:-1,j<w-1?' ':'\n');
	}

	return 0;
}
