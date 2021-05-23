#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b,c; cin>>a>>b>>c;
	puts(c-(a+b)>0 && 4*a*b<(c-(a+b))*(c-(a+b))?"Yes":"No");
	return 0;
}
