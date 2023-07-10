#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
// experiment
/*
	bool win[50][50][50]={};
	int n=30;
	rep(i,n) rep(j,n) rep(k,n) {
		if(i>0 && !win[i-1][j][k]) win[i][j][k]=true;
		if(j>0 && !win[i][j-1][k]) win[i][j][k]=true;
		if(k>0 && !win[i][j][k-1]) win[i][j][k]=true;
		if(i>0 && j>0 && !win[i-1][j-1][k]) win[i][j][k]=true;
		if(i>0 && k>0 && !win[i-1][j][k-1]) win[i][j][k]=true;
		if(j>0 && k>0 && !win[i][j-1][k-1]) win[i][j][k]=true;
		if(i>0 && j>0 && k>0 && !win[i-1][j-1][k-1]) win[i][j][k]=true;
	}
*/

	int n; scanf("%d",&n);
	bool win=false;
	rep(i,n){ int a; scanf("%d",&a); win|=(a%2==1); }
	puts(win?"first":"second");

	return 0;
}
