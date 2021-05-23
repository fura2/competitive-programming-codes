#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	vector U(h,vector(w,-1)),D(h,vector(w,h));
	vector L(h,vector(w,-1)),R(h,vector(w,w));
	rep(i,h) rep(j,w) if(B[i][j]=='#') {
		U[i][j]=D[i][j]=i;
		L[i][j]=R[i][j]=j;
	}
	rep(j,w) for(int i= 1 ;i< h;i++) U[i][j]=max(U[i][j],U[i-1][j]);
	rep(i,h) for(int j= 1 ;j< w;j++) L[i][j]=max(L[i][j],L[i][j-1]);
	rep(j,w) for(int i=h-2;i>=0;i--) D[i][j]=min(D[i][j],D[i+1][j]);
	rep(i,h) for(int j=w-2;j>=0;j--) R[i][j]=min(R[i][j],R[i][j+1]);

	lint ans=0;
	rep(i,h) rep(j,w) if(B[i][j]=='.') {
		ans+=(D[i][j]-U[i][j]-2)*(R[i][j]-L[i][j]-2);
	}
	printf("%lld\n",ans);

	return 0;
}
