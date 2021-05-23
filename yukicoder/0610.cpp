#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d",&a[i]), a[i]--;
	rep(i,n) scanf("%d",&b[i]), b[i]--;

	vector<int> pos(n);
	rep(i,n) pos[b[i]]=i;

	int mn=n;
	vector<int> ans;
	for(int i=n-1;i>=0;i--){
		if(pos[a[i]]<mn) ans.emplace_back(a[i]);
		mn=min(mn,pos[a[i]]);
	}
	sort(ans.begin(),ans.end());
	rep(i,ans.size()) printf("%d\n",ans[i]+1);

	return 0;
}
