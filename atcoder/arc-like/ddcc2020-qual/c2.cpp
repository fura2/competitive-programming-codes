// smart implementation

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,k; scanf("%d%d%d",&h,&w,&k);
	char B[300][301];
	rep(i,h) scanf("%s",B[i]);

	int ans[300][300]={};
	rep(i,h) rep(j,w) if(B[i][j]=='#') ans[i][j]=k--;
	rep(i,h){
		rep(j,w-1) if(ans[i][j+1]==0) ans[i][j+1]=ans[i][j];
		for(int j=w-1;j>0;j--) if(ans[i][j-1]==0) ans[i][j-1]=ans[i][j];
	}
	rep(j,w){
		rep(i,h-1) if(ans[i+1][j]==0) ans[i+1][j]=ans[i][j];
		for(int i=h-1;i>0;i--) if(ans[i-1][j]==0) ans[i-1][j]=ans[i][j];
	}

	rep(i,h) rep(j,w) printf("%d%c",ans[i][j],j<w-1?' ':'\n');

	return 0;
}
