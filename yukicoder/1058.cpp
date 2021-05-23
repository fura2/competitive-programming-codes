#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint P[]={100003,100019,100043,100049,100057,100069,100103,100109,100129};
	vector<lint> ans={1};
	rep(i,9) rep(j,i+1) ans.emplace_back(P[i]*P[j]);

	sort(ans.begin(),ans.end());

	int n; scanf("%d",&n); n--;
	printf("%lld\n",ans[n]);

	return 0;
}
