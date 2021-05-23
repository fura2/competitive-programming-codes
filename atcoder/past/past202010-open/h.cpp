#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,k; cin>>h>>w>>k;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	int cum[10][31][31]={};
	rep(i,h) rep(j,w) cum[B[i][j]-'0'][i+1][j+1]++;
	rep(d,10) rep(i,h) rep(j,w) {
		cum[d][i+1][j+1]+=cum[d][i+1][j]+cum[d][i][j+1]-cum[d][i][j];
	}

	int ans=0;
	for(int l=1;l<=min(h,w);l++){
		rep(i,h-l+1) rep(j,w-l+1) {
			int mx=0;
			rep(d,10){
				mx=max(mx,cum[d][i+l][j+l]-cum[d][i+l][j]-cum[d][i][j+l]+cum[d][i][j]);
			}
			if(mx+k>=l*l) ans=l;
		}
	}
	printf("%d\n",ans);

	return 0;
}
