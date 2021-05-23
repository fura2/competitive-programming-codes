#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int d; scanf("%d",&d);
	vector c(26,0);
	rep(j,26) scanf("%d",&c[j]);
	vector a(d,vector(26,0));
	rep(i,d) rep(j,26) scanf("%d",&a[i][j]);
	vector t(d,0);
	rep(i,d) scanf("%d",&t[i]), t[i]--;

	int ans=0;
	vector last(26,0);
	rep(i,d){
		ans+=a[i][t[i]];
		last[t[i]]=i+1;
		rep(j,26) ans-=c[j]*(i+1-last[j]);
		printf("%d\n",ans);
	}

	return 0;
}
