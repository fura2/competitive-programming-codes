#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint l,r,n; cin>>l>>r>>n;
	rep(i,n) printf("%lld\n",(r+n-i)/n-(l+n-1-i)/n);
	return 0;
}
