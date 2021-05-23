#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint h,w; scanf("%lld%lld",&h,&w);
	if(h==w) printf("%lld\n",(h*w+3)/4-1);
	else     printf("%lld\n",(h*w+1)/2-1);
	return 0;
}
