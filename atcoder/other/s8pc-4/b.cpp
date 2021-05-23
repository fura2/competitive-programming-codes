#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int n,k;
lint a[15];

lint dfs(int i){
	if(i==n){
		int cnt=0;
		lint mx=0;
		rep(j,n) if(a[j]>mx) {
			mx=a[j];
			cnt++;
		}
		return cnt>=k?0:INF;
	}

	lint mx=0;
	rep(j,i) mx=max(mx,a[j]);

	lint res=dfs(i+1);
	if(a[i]<=mx){
		lint tmp=a[i];
		a[i]=mx+1;
		res=min(res,dfs(i+1)+(mx+1-tmp));
		a[i]=tmp;
	}
	return res;
}

int main(){
	scanf("%d%d",&n,&k);
	rep(i,n) scanf("%lld",&a[i]);

	printf("%lld\n",dfs(0));

	return 0;
}
