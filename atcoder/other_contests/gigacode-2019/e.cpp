#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double INF=1e77;

struct car{ int x,v,d; };

int main(){
	int n,L; scanf("%d%d",&n,&L);
	vector<car> C;
	{
		int vs,ds; scanf("%d%d",&vs,&ds);
		C.emplace_back(car{0,vs,ds});
	}
	rep(i,n){
		int x,v,d; scanf("%d%d%d",&x,&v,&d);
		C.emplace_back(car{x,v,d});
	}
	C.emplace_back(car{L,0,0});

	sort(C.begin(),C.end(),[](const car& c,const car& d){ return c.x<d.x; });

	vector<double> dp(n+2,INF);
	dp[0]=0;
	rep(i,n+1) if(dp[i]<INF) {
		for(int j=i+1;j<n+2;j++) if(C[j].x<=C[i].x+C[i].d) {
			dp[j]=min(dp[j],dp[i]+1.0*(C[j].x-C[i].x)/C[i].v);
		}
	}

	if(dp[n+1]<INF) printf("%.9f\n",dp[n+1]);
	else            puts("impossible");

	return 0;
}
