#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a1,a2,b1,b2,c;
	cin>>a1>>a2>>b1>>b2>>c;

	vector<int> ans;
	if(c==a1 || c==a2) ans.emplace_back(b1), ans.emplace_back(b2);
	if(c==b1 || c==b2) ans.emplace_back(a1), ans.emplace_back(a2);
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());

	printf("%ld\n",ans.size());
	rep(i,ans.size()) printf("%d\n",ans[i]);

	return 0;
}
