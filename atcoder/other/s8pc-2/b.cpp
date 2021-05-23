#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint L;
int n,a[24];

vector<lint> ans;

void dfs(int i,lint x){
	if(x>L) return;
	if(i==n){
		ans.emplace_back(x);
		return;
	}
	if(x%a[i]!=0) dfs(i+1,x);
	dfs(i+1,x*a[i]);
}

int main(){
	scanf("%lld%d",&L,&n);
	rep(i,n) scanf("%d",&a[i]);

	reverse(a,a+n);
	dfs(0,1);

	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	printf("%ld\n",ans.size());

	return 0;
}
