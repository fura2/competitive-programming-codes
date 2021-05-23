#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; scanf("%d%d",&h,&w);
	static char B[3000][3001];
	rep(i,h) scanf("%s",B[i]);

	static int cum[3001][3001];
	rep(i,h) rep(j,w) cum[i+1][j+1]=cum[i+1][j]+cum[i][j+1]-cum[i][j]+(B[i][j]=='.'?1:0);

	int lo=1,hi=min(h,w)+1;
	while(hi-lo>1){
		int mi=(lo+hi)/2;
		bool ok=false;
		rep(i,h-mi+1) rep(j,w-mi+1) {
			if(cum[i+mi][j+mi]-cum[i+mi][j]-cum[i][j+mi]+cum[i][j]==0) ok=true;
		}
		if(ok) lo=mi;
		else   hi=mi;
	}
	printf("%d\n",(lo+1)/2);

	return 0;
}
