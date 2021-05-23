#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint k; scanf("%lld",&k);

	double ans=0;
	for(int n=1;n<20;n++){
		ans+=sin(k*n)/pow(n,n);
	}
	printf("%.15f\n",ans);

	return 0;
}
