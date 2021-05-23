#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

pair<int,int> input(){
	int x,y; scanf("%d%d",&x,&y); x--; y--;
	return {x,y};
}

void output(int x,int y){
	printf("%d %d\n",x+1,y+1);
	fflush(stdout);
}

int main(){
	int h,w; scanf("%d%d",&h,&w);

	bool B[50][50]={};
	B[0][0]=true;

	int cnt=0;
	rep(i,h) rep(j,w) if(!B[i][j]) cnt++;

	auto get_next=[&]()->pair<int,int>{
		if((h>=2 && B[h-2][w-1]) || (w>=2 && B[h-1][w-2])) return {h-1,w-1};
		rep(i,h) rep(j,w) if(!B[i][j]) {
			if(i==h-2 && j==w-1) continue;
			if(i==h-1 && j==w-2) continue;
			if((i>0 && B[i-1][j]) || (j>0 && B[i][j-1])) return {i,j};
		}
		return {-1,-1};
	};

	if((h==1 && w%2==0) || (w==1 && h%2==0) || (h>=2 && w>=2 && h*w%2==1)){
		puts("First");
		fflush(stdout);
		int x,y;
		while(1){
			tie(x,y)=get_next();
			output(x,y);
			B[x][y]=true;
			tie(x,y)=input();
			if(x<0) break;
			B[x][y]=true;
		}
	}
	else{
		puts("Second");
		fflush(stdout);
		int x,y;
		while(1){
			tie(x,y)=input();
			if(x<0) break;
			B[x][y]=true;
			tie(x,y)=get_next();
			output(x,y);
			B[x][y]=true;
		}
	}

	return 0;
}
