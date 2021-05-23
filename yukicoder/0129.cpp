#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n;
	int m; cin>>n>>m;

	constexpr int MOD=1e9;
	static int C[10001][10001];
	rep(i,m+1) C[i][0]=1;
	for(int i=1;i<=m;i++) for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;

	printf("%d\n",C[m][(n/1000)%m]);

	return 0;
}
