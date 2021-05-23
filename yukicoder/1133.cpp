#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m;
	string s; cin>>n>>m>>s;
	n++;

	vector B(n,vector(n,1));
	B[0][0]=0;
	int x=0,y=0;
	rep(i,m){
		if(s[i]=='R') x++;
		if(s[i]=='U') y++;
		if(s[i]=='L') x--;
		if(s[i]=='D') y--;
		B[y][x]=0;
	}

	for(int i=n-1;i>=0;i--) rep(j,n) printf("%d%c",B[i][j],j<n-1?' ':'\n');

	return 0;
}
