#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n;
double memo[101][101][101];

double dfs(int n0,int n1,int n2,int n3){
	if(memo[n0][n1][n2]!=-1) return memo[n0][n1][n2];

	if(n3==n) return memo[n0][n1][n2]=0;

	double res=1;
	if(n0>0) res+=dfs(n0-1,n1+1,n2,n3)*n0/n;
	if(n1>0) res+=dfs(n0,n1-1,n2+1,n3)*n1/n;
	if(n2>0) res+=dfs(n0,n1,n2-1,n3+1)*n2/n;
	res/=1-1.0*n3/n;
	return memo[n0][n1][n2]=res;
}

int main(){
	scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]), a[i]=min(a[i],3);

	int freq[4]={};
	rep(i,n) freq[a[i]]++;

	rep(i,n+1) rep(j,n+1) rep(k,n+1) memo[i][j][k]=-1;
	printf("%.9f\n",dfs(freq[0],freq[1],freq[2],freq[3]));

	return 0;
}
