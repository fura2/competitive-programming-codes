// O(N^3) solution with pruning (N=max{H,W})

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,k; scanf("%d%d%d",&h,&w,&k);
	static char B[3000][3001];
	rep(i,h) rep(j,w) B[i][j]='#';
	rep(i,k){
		int y,x; scanf("%d%d",&y,&x); y--; x--;
		B[y][x]='.';
	}

	static int cnt[3][3000][3000];
	rep(j,w) for(int i=h-1;i>=0;i--) if(B[i][j]=='#') {
		cnt[0][i][j]=(i<h-1?cnt[0][i+1][j]:0)+1;
	}
	rep(j,w) rep(i,h) if(B[i][j]=='#') {
		cnt[1][i][j]=(i>0?cnt[1][i-1][j]:0)+1;
	}
	rep(j,w){
		int y,x;
		for(y=0,x=j;y<h&&x<w;y++,x++);
		y--; x--;
		for(;y>=0&&x>=0;y--,x--) if(B[y][x]=='#') {
			cnt[2][y][x]=(y<h-1&&x<w-1?cnt[2][y+1][x+1]:0)+1;
		}
	}
	for(int i=1;i<h;i++){
		int y,x;
		for(y=i,x=0;y<h&&x<w;y++,x++);
		y--; x--;
		for(;y>=0&&x>=0;y--,x--) if(B[y][x]=='#') {
			cnt[2][y][x]=(y<h-1&&x<w-1?cnt[2][y+1][x+1]:0)+1;
		}
	}

	int ans=0;
	rep(i,h) rep(j,w) {
		int c=min(cnt[0][i][j],cnt[2][i][j]);
		for(int d=ans;d<c;d++){
			if(i+d>=h || j+d>=w) break;
			if(cnt[1][i+d][j+d]>=d+1) ans=max(ans,d+1);
		}
	}
	printf("%d\n",ans);

	return 0;
}
