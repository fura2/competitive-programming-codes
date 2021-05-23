// 100 points solution
// O(H*W)

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,n; scanf("%d%d%d",&h,&w,&n);
	static char B[5002][5003];
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

	static int sum[5003][5003];
	rep(i,h) rep(j,w) sum[i+1][j+1]=sum[i+1][j]+sum[i][j+1]-sum[i][j]+(B[i][j]=='#'?1:0);

	static int height[5002][5002];
	rep(i,h-1) rep(j,w) if(B[i+1][j]=='.') height[i+1][j]=height[i][j]+1;

	int ans=0;
	rep(i,h){
		static stack<pair<int,int>> S; // height, left position
		while(!S.empty()) S.pop();
		S.emplace(0,0);
		for(int j=1;j<w;j++){
			int left=j;
			while(S.top().first>height[i][j]){
				left=S.top().second;
				S.pop();
				if(sum[i+2][j]-sum[i+2][left]-sum[i+1][j]+sum[i+1][left]>0) ans++;
			}
			if(S.top().first<height[i][j]){
				S.emplace(height[i][j],left);
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}
