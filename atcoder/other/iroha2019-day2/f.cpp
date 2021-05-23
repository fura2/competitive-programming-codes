#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double INF=1e77;

double memo[11][11][11][11][11][11];

double dfs(int a1,int a2,int b1,int b2,int c1,int c2){
	double& res=memo[a1][a2][b1][b2][c1][c2];
	if(res!=-1) return res;

	int sum=0;
	sum+=100*a1+50*a2;
	sum+=100*b1+50*b2;
	sum+=100*c1+50*c2;
	if(sum==0) return res=0;

	double tmp1=INF;
	if(a1+a2>0){
		double tmp2=0;
		if(a1>0) tmp2+=dfs(a1-1,a2,b1,b2,c1,c2)*a1/(a1+a2);
		if(a2>0) tmp2+=dfs(a1,a2-1,b1,b2,c1,c2)*a2/(a1+a2);
		tmp1=min(tmp1,tmp2);
	}
	if(b1+b2>0){
		double tmp2=0;
		if(b1>0) tmp2+=dfs(a1,a2,b1-1,b2,c1,c2)*b1/(b1+b2);
		if(b2>0) tmp2+=dfs(a1,a2,b1,b2-1,c1,c2)*b2/(b1+b2);
		tmp1=min(tmp1,tmp2);
	}
	if(c1+c2>0){
		double tmp2=0;
		if(c1>0) tmp2+=dfs(a1,a2,b1,b2,c1-1,c2)*c1/(c1+c2);
		if(c2>0) tmp2+=dfs(a1,a2,b1,b2,c1,c2-1)*c2/(c1+c2);
		tmp1=min(tmp1,tmp2);
	}
	return res=sum-tmp1;
}

int main(){
	int a1,a2,b1,b2,c1,c2;
	cin>>a1>>a2>>b1>>b2>>c1>>c2;

	rep(i1,a1+1) rep(i2,a2+1) rep(j1,b1+1) rep(j2,b2+1) rep(k1,c1+1) rep(k2,c2+1) {
		memo[i1][i2][j1][j2][k1][k2]=-1;
	}
	printf("%.15f\n",dfs(a1,a2,b1,b2,c1,c2));

	return 0;
}
