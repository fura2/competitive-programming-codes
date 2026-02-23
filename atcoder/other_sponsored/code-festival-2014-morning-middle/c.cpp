#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	long double p;
	lint n; cin>>p>>n;

	printf("%.9Lf\n",(1-pow(1-2*p,n))/2);

	return 0;
}
