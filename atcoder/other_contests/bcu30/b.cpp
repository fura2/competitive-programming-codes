#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={-1,-2,-2,-1,1,2,2,1};
const int dy[]={2,1,-1,-2,-2,-1,1,2};

int main(){
	string B[9];
	rep(i,9) cin>>B[i];

	rep(i,9) rep(j1,9) for(int j2=j1+1;j2<9;j2++) {
		if(B[i][j1]==B[i][j2]){
			puts("No");
			return 0;
		}
	}
	rep(j,9) rep(i1,9) for(int i2=i1+1;i2<9;i2++) {
		if(B[i1][j]==B[i2][j]){
			puts("No");
			return 0;
		}
	}
	rep(i,9) rep(j,9) rep(k,8) {
		int x=i+dx[k],y=j+dy[k];
		if(0<=x && x<9 && 0<=y && y<9 && B[i][j]==B[x][y]){
			puts("No");
			return 0;
		}
	}
	puts("Yes");

	return 0;
}
