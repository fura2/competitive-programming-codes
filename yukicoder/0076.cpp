#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	double a[5]={1.0833333333333333,
				 1.2569444444444444,
				 1.5353009259259260,
				 1.6915991512345676,
				 2.0513639724794235};

	double p[6];
	rep(i,5){
		p[i]=a[i]-1;
		rep(j,i) p[i]-=p[j]*a[i-j-1];
	}
	p[5]=1-p[0]-p[1]-p[2]-p[3]-p[4];

	double ans[1000001]={0,1};
	rep(i,5) ans[i+2]=a[i];
	for(int i=7;i<=1e6;i++){
		ans[i]=1;
		rep(d,6) ans[i]+=p[d]*ans[i-d-1];
	}

	int q; scanf("%d",&q);
	rep(_,q){
		int n; scanf("%d",&n);
		printf("%.9f\n",ans[n]);
	}

	return 0;
}
