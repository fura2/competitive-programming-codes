#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,t; scanf("%d%d",&n,&t);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	map<int,lint> curr,next;
	curr[t]=0;
	rep(i,n){
		next.clear();
		for(auto [x,v]:curr){
			for(int x2:{x&a[i],x|a[i]}){
				lint v2=v+abs(x-x2);
				next[x2]=max(next[x2],v2);
			}
		}
		swap(curr,next);
	}

	lint ans=0;
	for(auto [x,v]:curr) ans=max(ans,v);
	printf("%lld\n",ans);

	return 0;
}
