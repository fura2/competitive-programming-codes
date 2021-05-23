#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b,c; cin>>a>>b>>c;
	lint k=c/(a-1+b);
	cout<<a*k+min(c%(a-1+b),a)<<'\n';
	return 0;
}
