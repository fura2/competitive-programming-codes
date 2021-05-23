#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int B[10][10]={};
	B[2][8]=1;
	B[3][9]=2;
	B[7][9]=3;

	int n; scanf("%d",&n);
	rep(i,n){
		int x1,y1,x2,y2; scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		swap(B[x1][y1],B[x2][y2]);
	}
	puts(B[5][8]==1&&B[4][8]==2&&B[6][8]==3?"YES":"NO");

	return 0;
}
