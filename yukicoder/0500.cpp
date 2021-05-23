#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; cin>>n;

	if(n>=50){
		puts("000000000000");
		return 0;
	}

	lint ans=1;
	bool over=false;
	rep(i,n){
		ans*=i+1;
		if(ans>=1e12) over=true;
		ans%=1000000000000LL;
	}
	if(over) printf("%012lld\n",ans);
	else     printf("%lld\n",ans);

	return 0;
}
