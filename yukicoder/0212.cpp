#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int P[]={2,3,5,7,11,13},C[]={4,6,8,9,10,12};

double ans;

void dfs(int p,int c,double prod=1){
	if(p+c==0){
		ans+=prod;
		return;
	}

	if(p>0){
		rep(i,6) dfs(p-1,c,prod*P[i]);
	}
	else{
		rep(i,6) dfs(p,c-1,prod*C[i]);
	}
}

int main(){
	int p,c; scanf("%d%d",&p,&c);
	dfs(p,c);
	printf("%.9f\n",ans/pow(6,p+c));
	return 0;
}
