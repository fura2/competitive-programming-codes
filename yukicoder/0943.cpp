#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	int v[18]={};
	rep(i,n) rep(j,n) {
		int x; scanf("%d",&x);
		if(x==1) v[i]|=1<<j;
	}
	int a[18];
	rep(i,n) scanf("%d",&a[i]);

	int ans=INF;
	rep(S,1<<n){
		int x=S;
		rep(_,n) rep(i,n) if((v[i]&x)==v[i]) x|=1<<i;
		if(x==(1<<n)-1){
			int cost=0;
			rep(i,n) if(S>>i&1) cost+=a[i];
			ans=min(ans,cost);
		}
	}
	printf("%d\n",ans);

	return 0;
}
