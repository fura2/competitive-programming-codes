#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,k;
double p[100];

bool filled[200];
map<vector<bool>,double> memo[101];

double dfs(int i){
	vector<bool> F(filled,filled+k);
	if(memo[i].count(F)>0) return memo[i][F];

	if(i==n) return memo[i][F]=count(filled,filled+k,false);

	double res=0;

	bool ok=false;
	rep(j,k) if(!filled[j]) {
		filled[j]=true;
		res+=p[i]*dfs(i+1);
		filled[j]=false;
		ok=true;
		break;
	}
	if(!ok) res+=p[i]*dfs(i+1);

	ok=false;
	rep(j,k) if(!filled[j] && (j==0 || !filled[j-1]) && (j==k-1 || !filled[j+1])) {
		filled[j]=true;
		res+=(1-p[i])*dfs(i+1);
		filled[j]=false;
		ok=true;
		break;
	}
	if(!ok) res+=(1-p[i])*dfs(i+1);

	return memo[i][F]=res;
}

int main(){
	scanf("%d%d",&n,&k);
	rep(i,n) scanf("%lf",&p[i]), p[i]/=100;

	printf("%.9f\n",dfs(0));

	return 0;
}
