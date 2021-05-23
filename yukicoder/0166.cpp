#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint h,w,n,k; scanf("%lld%lld%lld%lld",&h,&w,&n,&k);
	puts(h*w%n==k%n?"YES":"NO");
	return 0;
}
