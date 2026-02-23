#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int H,W,h,w; scanf("%d%d%d%d",&H,&W,&h,&w);
	char B[1000][1001];
	rep(i,h) scanf("%s",B[i]);

	vector<int> X,Y;
	rep(i,h) rep(j,w) if(B[i][j]=='#') {
		X.emplace_back(i);
		Y.emplace_back(j);
		X.emplace_back(i+H-h+1);
		Y.emplace_back(j+W-w+1);
	}
	sort(X.begin(),X.end()); X.erase(unique(X.begin(),X.end()),X.end());
	sort(Y.begin(),Y.end()); Y.erase(unique(Y.begin(),Y.end()),Y.end());

	int n=X.size(),m=Y.size();
	vector B2(n,vector(m,0));
	rep(i,h) rep(j,w) if(B[i][j]=='#') {
		int t=lower_bound(X.begin(),X.end(),i)-X.begin();
		int l=lower_bound(Y.begin(),Y.end(),j)-Y.begin();
		int b=lower_bound(X.begin(),X.end(),i+H-h+1)-X.begin();
		int r=lower_bound(Y.begin(),Y.end(),j+W-w+1)-Y.begin();
		B2[t][l]++;
		B2[t][r]--;
		B2[b][l]--;
		B2[b][r]++;
	}

	rep(i,n) rep(j,m-1) B2[i][j+1]+=B2[i][j];
	rep(j,m) rep(i,n-1) B2[i+1][j]+=B2[i][j];

	lint ans=0;
	rep(i,n) rep(j,m) if(B2[i][j]>0) {
		ans+=lint(X[i+1]-X[i])*(Y[j+1]-Y[j]);
	}
	printf("%lld\n",ans);

	return 0;
}
