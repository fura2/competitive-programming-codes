#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	double r;
	int n,m; scanf("%lf%d%d",&r,&n,&m);

	auto f=[&](int i){
		if(i<0 || n<i) return 0.0;
		return r*sqrt(1-pow(1-2.0*i/n,2));
	};

	double ans=0;
	for(int i=1;i<n+m;i++){
		ans+=2*max(f(i-m),f(i));
	}
	printf("%.9f\n",ans);

	return 0;
}
