#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; cin>>n;

	int m=sqrt(1.0L*n);
	cout<<2*m-(n/m==m?1:0)<<'\n';

	return 0;
}
