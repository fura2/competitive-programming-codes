#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n; scanf("%*d%*d%d",&n);
	vector<lint> x(n),y(n);
	rep(i,n) scanf("%lld%lld",&x[i],&y[i]);

	auto X=x,Y=y;
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());

	lint ans=INF;
	int x_ans=-1,y_ans=-1;
	for(int c1=max(n/2-2,0);c1<min(n/2+2,n);c1++){
		for(int c2=max(n/2-2,0);c2<min(n/2+2,n);c2++){
			lint cx=X[c1],cy=Y[c2],sum=0,mx=0;
			rep(i,n){
				sum+=abs(x[i]-cx)+abs(y[i]-cy);
				mx=max(mx,abs(x[i]-cx)+abs(y[i]-cy));
			}
			if(make_tuple(ans,x_ans,y_ans)>make_tuple(2*sum-mx,cx,cy)){
				ans=2*sum-mx;
				x_ans=cx;
				y_ans=cy;
			}
		}
	}
	printf("%lld\n%d %d\n",ans,x_ans,y_ans);

	return 0;
}
