#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,k; cin>>n>>k;
	lint mx=n*(n+1)/2;
	lint mn=(n-k)*(n-k+1)-mx;
	printf("%lld\n",(mx-mn)/2+1);
	return 0;
}
