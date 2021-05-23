#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint ask(lint x,lint y){
	printf("%lld %lld\n",x,y);
	fflush(stdout);
	lint res; scanf("%lld",&res);
	if(res==0) exit(0);
	return res;
}

int main(){
	lint a=ask(0,0);
	lint b=ask(1e9,0);
	ask((a-b+1e9)/2,(a+b-1e9)/2);
	return 0;
}
