#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	lint a,b,n; cin>>a>>b>>n;

	lint ans=INF;
	for(lint l=0;l<=a&&l<=(n+b-1)/b;l++){
		lint k=(n-l*b+a-1)/a;
		ans=min(ans,k*a+l*b);
	}
	cout<<ans<<'\n';

	return 0;
}
