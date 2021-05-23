#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int n,a[10][10],gr[10];

int dfs(int i){
	if(i==n){
		int res=0;
		rep(i,n) for(int j=i+1;j<n;j++) if(gr[i]==gr[j]) res+=a[i][j];
		return res;
	}

	int res=-INF;
	rep(k,3){
		gr[i]=k;
		res=max(res,dfs(i+1));
	}
	return res;
}

int main(){
	scanf("%d",&n);
	rep(i,n) for(int j=i+1;j<n;j++) scanf("%d",&a[i][j]);

	printf("%d\n",dfs(1));

	return 0;
}
