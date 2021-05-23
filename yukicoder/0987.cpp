#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,m;
	char op;
	cin>>n>>m>>op;
	vector<lint> b(m),a(n);
	rep(j,m) scanf("%lld",&b[j]);
	rep(i,n) scanf("%lld",&a[i]);

	rep(i,n) rep(j,m) printf("%lld%c",op=='+'?a[i]+b[j]:a[i]*b[j],j<m-1?' ':'\n');

	return 0;
}
