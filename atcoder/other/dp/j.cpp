#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n;
double memo[301][301][301];

double dfs(int a,int b,int c){
	if(a+b+c==0) return 0;

	if(memo[a][b][c]!=-1) return memo[a][b][c];

	double r=1.0*(n-a-b-c)/n,sum=1;
	if(a>0) sum+=dfs(a-1,b,c)*a/n;
	else    r+=1.0*a/n;
	if(b>0) sum+=dfs(a+1,b-1,c)*b/n;
	else    r+=1.0*b/n;
	if(c>0) sum+=dfs(a,b+1,c-1)*c/n;
	else    r+=1.0*c/n;
	return memo[a][b][c]=sum/(1-r);
}

int main(){
	int cnt[3]={}; scanf("%d",&n);
	rep(i,n){ int a; scanf("%d",&a); cnt[a-1]++; }

	rep(i,n+1) rep(j,n+1) rep(k,n+1) memo[i][j][k]=-1;

	printf("%.9f\n",dfs(cnt[0],cnt[1],cnt[2]));

	return 0;
}
