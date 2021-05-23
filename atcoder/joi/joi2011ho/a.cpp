#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,q; cin>>h>>w>>q;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	vector cum(3,vector(h+1,vector(w+1,0)));
	rep(i,h) rep(j,w) cum[0][i+1][j+1]=cum[0][i+1][j]+cum[0][i][j+1]-cum[0][i][j]+(B[i][j]=='J'?1:0);
	rep(i,h) rep(j,w) cum[1][i+1][j+1]=cum[1][i+1][j]+cum[1][i][j+1]-cum[1][i][j]+(B[i][j]=='O'?1:0);
	rep(i,h) rep(j,w) cum[2][i+1][j+1]=cum[2][i+1][j]+cum[2][i][j+1]-cum[2][i][j]+(B[i][j]=='I'?1:0);

	rep(_,q){
		int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d); a--; b--;
		printf("%d ", cum[0][c][d]-cum[0][a][d]-cum[0][c][b]+cum[0][a][b]);
		printf("%d ", cum[1][c][d]-cum[1][a][d]-cum[1][c][b]+cum[1][a][b]);
		printf("%d\n",cum[2][c][d]-cum[2][a][d]-cum[2][c][b]+cum[2][a][b]);
	}

	return 0;
}
