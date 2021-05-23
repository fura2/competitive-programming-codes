#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int n,cost1,cost2,a[2][20];

int mask[20]; // mask[i] = (仕事 i をやる前に終わらせないといけない仕事の集合)

int memo[1<<20][2][21];

int dfs(int S,int lr,int k){ // S : 終わった仕事の集合, lr : 今どっちの部屋にいるか, k : 部屋を移動した回数
	if(memo[S][lr][k]!=-1) return memo[S][lr][k];

	int& res=memo[S][lr][k];
	if(S==(1<<n)-1) return res=0;

	// 残っている仕事のうち今できるものについて, 今いる部屋でやる方がいいものはまとめて処理 (定数倍高速化)
	int S2=S,c=0;
	rep(i,n) if(~S>>i&1 && (mask[i]&S)==mask[i]) {
		if(a[lr][i]<=a[lr^1][i]){
			S2|=1<<i;
			c+=a[lr][i];
		}
	}
	if(S2!=S) return res=dfs(S2,lr,k)+c;

	res=INF;
	rep(i,n) if(~S>>i&1 && (mask[i]&S)==mask[i]) {
		res=min(res,dfs(S|1<<i,lr,k)+a[lr][i]);
		res=min(res,dfs(S|1<<i,lr^1,k+1)+a[lr^1][i]+k*cost1+cost2);
	}
	return res;
}

int main(){
	int m; scanf("%d%d%d%d",&n,&m,&cost1,&cost2);
	rep(i,n) rep(j,2) scanf("%d",&a[j][i]);

	bool A[20][20]={};
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		A[u][v]=true;
	}
	rep(k,n) rep(i,n) rep(j,n) A[i][j]|=A[i][k]&&A[k][j];

	rep(i,n) rep(p,n) if(A[p][i]) mask[i]|=1<<p;

	memset(memo,-1,sizeof memo);
	printf("%d\n",min(dfs(0,0,0),dfs(0,1,0)));

	return 0;
}
