#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b,c,d; cin>>a>>b>>c>>d;
	cout<<a%d*b%d*c%d<<'\n';
	return 0;
}
