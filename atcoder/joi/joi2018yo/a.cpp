#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a,b,c,d; cin>>n>>a>>b>>c>>d;
	cout<<min((n+a-1)/a*b,(n+c-1)/c*d)<<'\n';
	return 0;
}
