#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	vector B(1001,vector(1001,0));
	rep(i,n){
		int l,t,r,b; scanf("%d%d%d%d",&l,&t,&r,&b);
		B[t][l]++;
		B[t][r]--;
		B[b][l]--;
		B[b][r]++;
	}

	rep(y,1001) rep(x,1000) B[y][x+1]+=B[y][x];
	rep(x,1001) rep(y,1000) B[y+1][x]+=B[y][x];

	vector<int> ans(n+1);
	rep(y,1001) rep(x,1001) ans[B[y][x]]++;
	rep(i,n) printf("%d\n",ans[i+1]);

	return 0;
}
