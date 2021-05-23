#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int q,n; scanf("%d%d",&q,&n);
	int a[130][130];
	rep(i,n) rep(j,n) scanf("%d",&a[i][j]);

	lint sum[131][131]={};
	rep(i,n) rep(j,n) sum[i+1][j+1]=sum[i+1][j]+sum[i][j+1]-sum[i][j]+a[i][j];

	rep(_,q){
		int y0,x0; scanf("%d%d",&y0,&x0); y0--; x0--;

		lint ans=0;
		map<lint,int> f;
		rep(i,y0+1) for(int j=y0+1;j<=n;j++) {
			f.clear();
			rep(k,n+1){
				lint b=sum[j][k]-sum[i][k];
				if(k<=x0) ++f[b];
				else      ans+=f[b];
			}
		}
		printf("%lld\n",ans);
	}

	return 0;
}
