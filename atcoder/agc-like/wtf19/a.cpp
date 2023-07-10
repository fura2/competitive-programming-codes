#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> ans;
	int pre=-1;
	while(1){
		rep(i,n) if(i!=pre && a[i]==0) {
			puts("-1");
			return 0;
		}
		if(k==0){
			rep(i,n) rep(_,a[i]) ans.emplace_back(i);
			break;
		}

		vector<int> tmp;
		rep(i,n) if(i!=pre) {
			a[i]--;
			tmp.emplace_back(i);
		}
		sort(tmp.begin(),tmp.end(),[&](int i,int j){
			return a[i]>a[j];
		});
		pre=tmp.back();
		for(int i:tmp) ans.emplace_back(i);
		k--;
	}

	printf("%ld\n",ans.size());
	rep(i,ans.size()) printf("%d%c",ans[i]+1,i+1<ans.size()?' ':'\n');

	return 0;
}
