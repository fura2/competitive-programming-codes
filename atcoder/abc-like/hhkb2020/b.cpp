#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	int ans=0;
	rep(i,h) rep(j,w) {
		if(i<h-1 && B[i][j]=='.' && B[i+1][j]=='.') ans++;
		if(j<w-1 && B[i][j]=='.' && B[i][j+1]=='.') ans++;
	}
	cout<<ans<<'\n';

	return 0;
}
