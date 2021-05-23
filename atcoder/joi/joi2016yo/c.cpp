#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	vector cum(3,vector(h+1,vector(w+1,0)));
	rep(k,3) rep(i,h) rep(j,w) {
		cum[k][i+1][j+1]=cum[k][i+1][j]+cum[k][i][j+1]-cum[k][i][j]+(B[i][j]=="WBR"[k]?1:0);
	}

	int ans=h*w;
	for(int i1=1;i1<h;i1++) for(int i2=i1+1;i2<h;i2++) {
		ans=min(ans,i1*w-cum[0][i1][w]+(i2-i1)*w-(cum[1][i2][w]-cum[1][i1][w])+(h-i2)*w-(cum[2][h][w]-cum[2][i2][w]));
	}
	cout<<ans<<'\n';

	return 0;
}
