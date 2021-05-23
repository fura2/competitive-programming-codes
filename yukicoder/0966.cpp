#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int q; scanf("%d",&q);
	rep(_,q){
		lint a,b,c; scanf("%lld%lld%lld",&a,&b,&c);

		lint ans=INF;
		if(b>=3){ // b を最大値にする
			lint a2=a,c2=c,cost=0;
			if(a>=b) a2=b-1, cost+=a-b+1;
			if(c>=b) c2=b-1, cost+=c-b+1;
			if(a2==c2) a2--, cost++;
			if(a2==0) cost=INF;
			ans=min(ans,cost);
		}
		if(a>=2 && c>=2){ // b を最小値にする
			lint a2=a,c2=c,cost=0;
			if(a==c){
				a2--; cost++;
			}
			cost+=max({b-a2+1,b-c2+1,0LL});
			if(a2==1) cost=INF;
			ans=min(ans,cost);
		}
		printf("%lld\n",ans<INF?ans:-1);
	}

	return 0;
}
