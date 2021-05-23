#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,sy,sx,gy,gx;
	scanf("%d%d%d%d%d%d",&h,&w,&sy,&sx,&gy,&gx);
	printf("%d\n",abs(gy-sy)+abs(gx-sx));
	return 0;
}
