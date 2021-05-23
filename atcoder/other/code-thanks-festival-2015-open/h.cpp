#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int h,w,tar; cin>>h>>w>>tar;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	vector cum(h+1,vector(w+1,0));
	rep(i,h) rep(j,w) cum[i+1][j+1]=cum[i][j+1]+cum[i+1][j]-cum[i][j]+B[i][j]-'0';

	vector freq(10,vector(h+1,vector(w+1,0)));
	rep(i,h) rep(j,w) freq[B[i][j]-'0'][i+1][j+1]++;
	for(int k=1;k<10;k++){
		rep(i,h) rep(j,w) freq[k][i+1][j+1]+=freq[k][i][j+1]+freq[k][i+1][j]-freq[k][i][j];
	}

	lint ans=0;
	rep(l,w) for(int r=l+3;r<=w;r++) {
		vector<int> a(h);
		rep(i,h) a[i]=cum[i+1][r]-cum[i+1][l]-cum[i][r]+cum[i][l];

		for(int cen=1;cen<10;cen++){
			int sum=0;
			for(int t=0,b=0;t<h;t++){
				while(b<h && sum<tar+cen){
					sum+=a[b];
					b++;
				}
				if(b-t>=3 && sum==tar+cen){
					ans+=freq[cen][b-1][r-1]-freq[cen][b-1][l+1]-freq[cen][t+1][r-1]+freq[cen][t+1][l+1];
				}
				sum-=a[t];
			}
		}
	}
	printf("%lld\n",ans);

	return 0;
}
