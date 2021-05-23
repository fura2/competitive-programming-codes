#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,m; cin>>n>>m;
	vector<lint> fib(n+1);
	fib[1]=1;
	rep(i,n-2) fib[i+2]=(fib[i]+fib[i+1])%m;
	cout<<fib[n-1]<<'\n';
	return 0;
}
