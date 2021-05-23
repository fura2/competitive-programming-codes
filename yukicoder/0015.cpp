#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint W; scanf("%d%lld",&n,&W);
	vector<int> w(n);
	rep(i,n) scanf("%d",&w[i]);

	vector<pair<lint,int>> Sum(1<<(n+1)/2);
	rep(S,1<<(n+1)/2){
		lint sum=0;
		rep(i,(n+1)/2) if(S>>i&1) sum+=w[n/2+i];
		Sum[S]={sum,S};
	}
	sort(Sum.begin(),Sum.end());

	vector<vector<int>> Ans;
	rep(S,1<<n/2){
		lint sum=0;
		rep(i,n/2) if(S>>i&1) sum+=w[i];
		if(sum>W) continue;

		auto it1=lower_bound(Sum.begin(),Sum.end(),make_pair(W-sum,0));
		auto it2=upper_bound(Sum.begin(),Sum.end(),make_pair(W-sum,1<<29));
		for(;it1!=it2;++it1){
			int T=it1->second;
			vector<int> res;
			rep(i,n/2) if(S>>i&1) res.emplace_back(i);
			rep(i,(n+1)/2) if(T>>i&1) res.emplace_back(n/2+i);
			Ans.emplace_back(res);
		}
	}

	sort(Ans.begin(),Ans.end());
	for(auto& ans:Ans) rep(i,ans.size()) printf("%d%c",ans[i]+1,i+1<ans.size()?' ':'\n');

	return 0;
}
