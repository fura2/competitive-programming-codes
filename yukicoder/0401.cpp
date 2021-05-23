#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

int main(){
	int n; scanf("%d",&n);

	int a[30][30]={},y=0,x=0,k=0;
	rep(i,n*n){
		a[y][x]=i+1;
		int y2=y+dy[k],x2=x+dx[k];
		if(y2<0 || n<=y2 || x2<0 || n<=x2 || a[y2][x2]!=0) k=(k+1)%4;
		y+=dy[k];
		x+=dx[k];
	}
	rep(i,n) rep(j,n) printf("%03d%c",a[i][j],j<n-1?' ':'\n');

	return 0;
}
