#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> x(n),y(n);
	rep(i,n) scanf("%d%d",&x[i],&y[i]);

	int ans=0;
	rep(i,n) rep(j,i) {
		int cnt=0;
		rep(k,n){
			int vx1=x[j]-x[i],vy1=y[j]-y[i];
			int vx2=x[k]-x[i],vy2=y[k]-y[i];
			if(vx1*vy2-vy1*vx2==0) cnt++;
		};
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);

	return 0;
}
