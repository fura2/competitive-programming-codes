#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int q; scanf("%d",&q);
	rep(_,q){
		int h,w; scanf("%d%d",&h,&w);

		static char B[1000][1001];
		rep(i,4) rep(j,4) B[i][j]='A'+(i*4+j)%3;
		rep(i,4) for(int j=4;j<w;j++) B[i][j]='A'+i%3;
		for(int i=4;i<h;i++) rep(j,4) B[i][j]='A'+j%3;
		for(int i=4;i<h;i++) for(int j=4;j<w;j++) B[i][j]='A';
		rep(i,h) B[i][w]='\0';

		rep(i,h) puts(B[i]);
	}

	return 0;
}
