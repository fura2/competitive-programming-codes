#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,g,v; cin>>n>>g>>v;
	printf("%.15f\n",n/5*g*1.0/v);
	return 0;
}
