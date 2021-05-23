#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,L; scanf("%d%d",&n,&L);
	vector<int> x1(n),y1(n),z1(n),x2(n),y2(n),z2(n);
	rep(i,n) scanf("%d%d%d%d%d%d",&x1[i],&y1[i],&z1[i],&x2[i],&y2[i],&z2[i]);

	vector<int> X,Y,Z;
	rep(i,n){
		X.emplace_back(x1[i]);
		X.emplace_back(x2[i]);
		Y.emplace_back(y1[i]);
		Y.emplace_back(y2[i]);
		Z.emplace_back(z1[i]);
		Z.emplace_back(z2[i]);
	}
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
	sort(Z.begin(),Z.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	Y.erase(unique(Y.begin(),Y.end()),Y.end());
	Z.erase(unique(Z.begin(),Z.end()),Z.end());

	int cnt[100][100][100]={};
	rep(i,n){
		int ix1=lower_bound(X.begin(),X.end(),x1[i])-X.begin();
		int ix2=lower_bound(X.begin(),X.end(),x2[i])-X.begin();
		int iy1=lower_bound(Y.begin(),Y.end(),y1[i])-Y.begin();
		int iy2=lower_bound(Y.begin(),Y.end(),y2[i])-Y.begin();
		int iz1=lower_bound(Z.begin(),Z.end(),z1[i])-Z.begin();
		int iz2=lower_bound(Z.begin(),Z.end(),z2[i])-Z.begin();
		for(int jx=ix1;jx<ix2;jx++) for(int jy=iy1;jy<iy2;jy++) for(int jz=iz1;jz<iz2;jz++) {
			cnt[jx][jy][jz]++;
		}
	}

	lint ans=0;
	rep(i,X.size()-1) rep(j,Y.size()-1) rep(k,Z.size()-1) if(cnt[i][j][k]>=L) {
		ans+=1LL*(X[i+1]-X[i])*(Y[j+1]-Y[j])*(Z[k+1]-Z[k]);
	}
	printf("%lld\n",ans);

	return 0;
}
