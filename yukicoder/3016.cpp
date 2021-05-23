#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	map<lint,int> f;
	rep(i,n){
		lint a; scanf("%lld",&a);
		++f[a];
	}
	rep(j,m){
		lint b; scanf("%lld",&b);
		printf("%d%c",f[b],j<m-1?' ':'\n');
	}
	return 0;
}
