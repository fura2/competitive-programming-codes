#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	vector dp1(h,vector(w,0));
	vector dp2(h,vector(w,0));
	rep(i,h){
		int cnt=0;
		for(int j=w-1;j>=0;j--){
			if(B[i][j]=='O') cnt++;
			if(B[i][j]=='J') dp1[i][j]=cnt;
		}
	}
	rep(j,w){
		int cnt=0;
		for(int i=h-1;i>=0;i--){
			if(B[i][j]=='I') cnt++;
			if(B[i][j]=='J') dp2[i][j]=cnt;
		}
	}

	lint ans=0;
	rep(i,h) rep(j,w) ans+=dp1[i][j]*dp2[i][j];
	cout<<ans<<'\n';

	return 0;
}
