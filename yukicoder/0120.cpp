#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void solve(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> X=a;
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());

	vector<int> hist(n);
	rep(i,n) hist[lower_bound(X.begin(),X.end(),a[i])-X.begin()]++;

	int lo=0,hi=n;
	while(hi-lo>1){
		int mi=(lo+hi)/2;
		int cnt=0;
		rep(x,n) cnt+=min(hist[x],mi);
		if(cnt>=3*mi) lo=mi;
		else          hi=mi;
	}
	printf("%d\n",lo);
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
