#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

enum{WIN,DRAW,LOSE};
int memo[14][14][14][14][53];

int dfs(int a,int b,int c,int d,int n,int m){
	if(memo[a][b][c][d][n]!=-1) return memo[a][b][c][d][n];

	bool draw=false;
	if(a>0){
		for(int i=1;i<=min(3,a);i++){
			int res=dfs(a-i,b,c,d,i==a?m/2:m,n+i+(i==a?(m+1)/2:0));
			if(res==LOSE) return memo[a][b][c][d][n]=WIN;
			if(res==DRAW) draw=true;
		}
	}
	if(b>0){
		for(int i=1;i<=min(3,b);i++){
			int res=dfs(a,b-i,c,d,i==b?m/2:m,n+i+(i==b?(m+1)/2:0));
			if(res==LOSE) return memo[a][b][c][d][n]=WIN;
			if(res==DRAW) draw=true;
		}
	}
	if(c>0){
		for(int i=1;i<=min(3,c);i++){
			int res=dfs(a,b,c-i,d,i==c?m/2:m,n+i+(i==c?(m+1)/2:0));
			if(res==LOSE) return memo[a][b][c][d][n]=WIN;
			if(res==DRAW) draw=true;
		}
	}
	if(d>0){
		for(int i=1;i<=min(3,d);i++){
			int res=dfs(a,b,c,d-i,i==d?m/2:m,n+i+(i==d?(m+1)/2:0));
			if(res==LOSE) return memo[a][b][c][d][n]=WIN;
			if(res==DRAW) draw=true;
		}
	}
	return memo[a][b][c][d][n]=(draw?DRAW:LOSE);
}

int main(){
	int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
	memset(memo,-1,sizeof memo);
	int ans=dfs(a,b,c,d,0,0);
	puts(ans==WIN?"Taro":ans==DRAW?"Draw":"Jiro");
	return 0;
}
