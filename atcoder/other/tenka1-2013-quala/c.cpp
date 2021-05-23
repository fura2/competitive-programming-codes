#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

/*
int h,w,B[30][30];

int dfs(int y,int x){
	if(y==h) return 1;
	if(x==w) return dfs(y+1,0);

	int res=0;
	for(int a=1;a<=3;a++){
		B[y][x]=a;
		bool ok=true;
		rep(i,y) if(B[i][x]==B[y][x] && y-i<=a) ok=false;
		rep(j,x) if(B[y][j]==B[y][x] && x-j<=a) ok=false;
		if(ok) res+=dfs(y,x+1);
	}
	return res;
}
*/

int main(){
// experiment
//	for(h=1;h<30;h++) for(w=1;w<30;w++) printf("%2d%c",dfs(0,0),w<29?' ':'\n');

	int h,w; scanf("%d%d",&h,&w);
	if(h>w) swap(h,w);
	if(h==1){
		int a[]={3,6,8,8,8,8,9,10,9};
		if(w<=5) printf("%d\n",a[w-1]);
		else     printf("%d\n",a[5+(w-6)%4]);
	}
	else if(h==2 && w==2) puts("18");
	else if(h==2 && w==3) puts("20");
	else if(h==2 && w==4) puts("16");
	else if(h==3 && w==3) puts("28");
	else{
		int a[]={16,18,20,18};
		printf("%d\n",a[(h+w-7)%4]);
	}

	return 0;
}
