#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; cin>>n;
	cout<<n/2+(n%2==1?3:0)<<'\n';
	return 0;
}
