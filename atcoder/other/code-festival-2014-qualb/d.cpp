#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> h(n);
	rep(i,n) scanf("%d",&h[i]);

	vector<pair<int,int>> p(n);
	rep(i,n) p[i]={h[i],i};
	sort(p.rbegin(),p.rend());

	vector<int> ans(n);
	int pre=0;
	set<int> S={-1,n};
	rep(i,n){
		int idx=p[i].second;
		auto it=S.upper_bound(idx);
		int r=*it;
		int l=(*--it)+1;
		ans[idx]=r-l-1;

		if(i==n-1 || p[i+1].first<p[i].first){
			for(;pre<=i;pre++) S.emplace(p[pre].second);
		}
	}

	rep(i,n) printf("%d\n",ans[i]);

	return 0;
}
