#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,x,a,b; cin>>n>>x>>a>>b;
	cout<<min((x+a-1)/a,((1LL<<(n-1))-x+b-1)/b)<<'\n';
	return 0;
}
