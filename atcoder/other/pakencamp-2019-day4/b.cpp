#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; cin>>n;

	lint ans=1,f=1;
	rep(i,n) f*=5, ans+=f;
	cout<<ans<<'\n';

	return 0;
}
