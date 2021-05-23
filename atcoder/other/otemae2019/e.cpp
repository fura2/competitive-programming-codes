#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int n;
lint d[500000],dsum[500001];

lint f(lint t,int i){
	return max(t+i-dsum[i],0LL)-i;
}

int main(){
	int q; scanf("%d%d",&n,&q);
	rep(i,n) scanf("%lld",&d[i]), dsum[i+1]=dsum[i]+d[i];

	rep(_,q){
		lint t,l,r; scanf("%lld%lld%lld",&t,&l,&r); r++;

		if(f(t,0)<l || r<=f(t,n)){
			puts("0");
			continue;
		}

		int lo=0,hi=n+1;
		while(hi-lo>1){
			int mi=(lo+hi)/2;
			if(f(t,mi)>=l) lo=mi;
			else           hi=mi;
		}
		int ans1=lo;

		lo=-1; hi=n;
		while(hi-lo>1){
			int mi=(lo+hi)/2;
			if(f(t,mi)<r) hi=mi;
			else          lo=mi;
		}
		int ans2=hi;

		printf("%d\n",ans1-ans2+1);
	}

	return 0;
}
