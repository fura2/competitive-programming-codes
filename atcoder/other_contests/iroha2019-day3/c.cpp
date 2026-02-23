#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

random_device seed_gen;
mt19937 rng(seed_gen());

int main(){
	int n,k; scanf("%d%d",&n,&k);

	vector<lint> sum(n);
	vector<pair<int,lint>> ans(k);
	rep(i,k-(2*n-1)){
		ans[i]=make_pair(0,i+1LL);
		sum[0]+=i+1;
	}
	for(int i=k-(2*n-1);i<k-n;i++){
		int id=i-(k-(2*n-1));
		lint x=rng();
		ans[i]=make_pair(id,x);
		sum[id]+=x;
	}
	for(int i=k-n;i<k;i++){
		int id=i-(k-n);
		lint x=lint(1e14)-sum[id];
		ans[i]=make_pair(id,x);
		sum[id]+=x;
	}

	rep(i,k) printf("%lld%c",ans[i].second,i<k-1?' ':'\n');
	puts("YES");
	rep(i,k) printf("%d%c",ans[i].first+1,i<k-1?' ':'\n');

	return 0;
}
