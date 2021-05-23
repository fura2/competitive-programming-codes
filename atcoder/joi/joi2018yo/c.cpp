#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int h,w; scanf("%d%d",&h,&w);
	vector B(h,vector(w,0));
	rep(i,h) rep(j,w) scanf("%d",&B[i][j]);

	int ans=INF;
	rep(i,h) rep(j,w) {
		int tmp=0;
		rep(x,h) rep(y,w) tmp+=B[x][y]*min(abs(i-x),abs(j-y));
		ans=min(ans,tmp);
	}
	printf("%d\n",ans);

	return 0;
}
