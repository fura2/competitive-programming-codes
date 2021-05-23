#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

/*
	c1*c4-c2*c3 = (c1*c3-c2^2)*(z1+z2)
	c2*c4-c3^2 = (c1*c3-c2^2)*z1*z2
*/

int main(){
	lint c1,c2,c3,c4; cin>>c1>>c2>>c3>>c4;
	puts((c1*c4-c2*c3)*(c1*c4-c2*c3)-4*(c1*c3-c2*c2)*(c2*c4-c3*c3)>=0?"R":"I");
	return 0;
}
