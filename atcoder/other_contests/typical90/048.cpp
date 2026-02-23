#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<lint> a(2*n);
	rep(i,n){
		lint x,y; scanf("%lld%lld",&x,&y);
		a.emplace_back(y);
		a.emplace_back(x-y);
	}

	sort(a.rbegin(),a.rend());

	printf("%lld\n",accumulate(a.begin(),a.begin()+k,0LL));

	return 0;
}
