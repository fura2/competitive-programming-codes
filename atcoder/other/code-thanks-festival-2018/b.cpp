#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint x,y; scanf("%lld%lld",&x,&y);

	if(3*x-y>=0 && 3*y-x>=0 && (3*x-y)%8==0 && (3*y-x)%8==0){
		puts("Yes");
	}
	else{
		puts("No");
	}

	return 0;
}
