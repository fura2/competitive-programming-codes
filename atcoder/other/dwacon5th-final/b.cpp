#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> cum(n+1);
	rep(i,n) cum[i+1]=cum[i]^a[i];

	vector<int> ans(n+1);
	multiset<int> S(cum.begin()+1,cum.end()-1);
	rep(i,n-1){
		int res=0;
		for(int b=29;b>=0;b--){
			res|=(ans[i]>>b&1)<<b;
			int mask=~((1<<b)-1);
			auto it=S.lower_bound(res);
			if(it==S.end() || ((*it)&mask)!=res){
				res^=1<<b;
			}
		}
		S.erase(S.find(res));
		ans[i+1]=res;
	}
	ans[n]=cum[n];

	for(int i=n;i>0;i--) ans[i]^=ans[i-1];

	rep(i,n) printf("%d%c",ans[i+1],i<n-1?' ':'\n');

	return 0;
}
