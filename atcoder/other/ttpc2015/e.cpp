#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector B(n,vector(n,0));
	rep(i,n) rep(j,n) B[i][j]=((i+j)%2==0?1:-1);

	vector<int> X,Y;
	rep(_,k){
		int x,y; scanf("%d%d",&x,&y); x--; y--;
		B[x][y]*=-1;
		for(int d=-1;d<=1;d++){
			if(0<=x+d && x+d<n) X.emplace_back(x+d);
			if(0<=y+d && y+d<n) Y.emplace_back(y+d);
		}
	}
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	sort(Y.begin(),Y.end());
	Y.erase(unique(Y.begin(),Y.end()),Y.end());

	vector cum(n+1,vector(n+1,0));
	rep(i,n) rep(j,n) cum[i+1][j+1]=cum[i+1][j]+cum[i][j+1]-cum[i][j]+B[i][j];

	int ans=0;
	rep(i1,X.size()) for(int i2=i1;i2<X.size();i2++) {
		rep(j1,Y.size()) for(int j2=j1;j2<Y.size();j2++) {
			int t=X[i1],b=X[i2]+1;
			int l=Y[j1],r=Y[j2]+1;
			ans=max(ans,abs(cum[b][r]-cum[t][r]-cum[b][l]+cum[t][l]));
		}
	}
	printf("%d\n",ans);

	return 0;
}
