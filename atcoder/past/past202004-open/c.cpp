#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	vector<string> B(n);
	rep(i,n) cin>>B[i];

	for(int i=n-2;i>=0;i--) rep(j,2*n-1) if(B[i][j]=='#') {
		if(j>0 && B[i+1][j-1]=='X')     B[i][j]='X';
		if(B[i+1][j]=='X')              B[i][j]='X';
		if(j<2*n-2 && B[i+1][j+1]=='X') B[i][j]='X';
	}
	rep(i,n) cout<<B[i]<<'\n';

	return 0;
}
