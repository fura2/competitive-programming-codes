#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b,c; cin>>a>>b>>c;

	lint x=1;
	rep(i,b) x*=c;
	puts(a<x?"Yes":"No");

	return 0;
}
