#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<string> rot(vector<string> B){
	int h=B.size(),w=B[0].size();
	vector<string> B2(w,string(h,'?'));
	rep(i,h) rep(j,w) B2[j][h-1-i]=B[i][j];
	return B2;
}

int main(){
	int r,k,h,w; cin>>r>>k>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	rep(i,r/90) B=rot(B);

	h=B.size();
	w=B[0].size();
	rep(i,k*h){
		rep(j,k*w){
			putchar(B[i/k][j/k]);
		}
		puts("");
	}

	return 0;
}
