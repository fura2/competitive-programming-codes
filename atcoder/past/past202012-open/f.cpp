#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(m),b(m),c(m);
	rep(i,m) scanf("%d%d%d",&a[i],&b[i],&c[i]), a[i]--, b[i]--, c[i]--;

	auto check=[&](int S){
		rep(i,m) if(S>>a[i]&1 && S>>b[i]&1 && S>>c[i]&1) return false;
		return true;
	};

	int ans=0;
	rep(S,1<<n) if(check(S)) {
		int cnt=0;
		rep(i,n) if(~S>>i&1 && !check(S|1<<i)) cnt++;
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);

	return 0;
}
