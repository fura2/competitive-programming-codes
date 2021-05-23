#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,m;
	lint k;
	char op;
	cin>>n>>m>>k>>op;
	vector<lint> b(m),a(n);
	rep(j,m) cin>>b[j];
	rep(i,n) cin>>a[i];

	sort(b.begin(),b.end());

	lint ans=0;
	rep(i,n) ans+=b.end()-lower_bound(b.begin(),b.end(),op=='+'?k-a[i]:(k+a[i]-1)/a[i]);
	cout<<ans<<'\n';

	return 0;
}
