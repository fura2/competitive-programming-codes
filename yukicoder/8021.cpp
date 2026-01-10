#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int q; scanf("%d",&q);
	rep(_,q){
		int x1,x2,y1,y2; scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
		printf("SELECT count(*) FROM point WHERE %d<=x AND x<=%d AND %d<=y AND y<=%d;\n",x1,x2,y1,y2);
		fflush(stdout);
	}
	return 0;
}
