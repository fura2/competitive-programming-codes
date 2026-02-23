// only for subtasks 1, 2, 3, 5
// O(H^2*W^2)

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int h,w;
char B[5002][5003];
int sum[5003][5003];

inline int f(int t,int l,int b,int r){ return sum[b][r]-sum[b][l]-sum[t][r]+sum[t][l]; }

int main(){
int q; scanf("%d",&q);
rep(_,q){
	int n; scanf("%d%d%d",&h,&w,&n);
	rep(j,w+2) B[0][j]=B[h+1][j]='#';
	rep(i,h){
		B[i+1][0]=B[i+1][w+1]='#';
		rep(j,w) B[i+1][j+1]='.';
	}
	rep(i,n){
		int y,x; scanf("%d%d",&y,&x);
		B[y][x]='#';
	}
	h+=2;
	w+=2;

	rep(i,h) rep(j,w) sum[i+1][j+1]=sum[i+1][j]+sum[i][j+1]-sum[i][j]+(B[i][j]=='#'?1:0);

	lint ans=0;
	rep(i1,h) rep(j1,w) for(int i2=i1+1;i2<=h;i2++) for(int j2=j1+1;j2<=w;j2++) if(f(i1,j1,i2,j2)==0) {
		if(f(i1-1,j1,i2,j2)>0
		&& f(i1,j1-1,i2,j2)>0
		&& f(i1,j1,i2+1,j2)>0
		&& f(i1,j1,i2,j2+1)>0) ans++;
	}
	printf("%lld\n",ans);
}
	return 0;
}
