#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double EPS=1e-8;
const double PI=acos(-1);

void solve(){
	double x[6],y[6];
	rep(i,6) scanf("%lf%lf",&x[i],&y[i]);

	int idx=-1;
	rep(i,6) if(x[i]>0 && y[i]>-EPS && (idx==-1 || y[i]<y[idx])) idx=i;
	printf("%.9f\n",atan2(y[idx],x[idx])*180/PI);
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
