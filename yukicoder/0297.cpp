#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

map<vector<int>,pair<lint,lint>> memo[15][15];

pair<lint,lint> dfs(vector<int> a,int plus,int minus){
	if(a.empty()) return {-INF,INF};

	if(memo[plus][minus].count(a)>0) return memo[plus][minus][a];

	lint mx=-INF,mn=INF;
	int n=a.size();
	rep(S,1<<n){
		if(S==0 || (plus==0 && minus==0 && S!=(1<<n)-1)) continue;

		vector<int> b,c;
		rep(i,n){
			if(S>>i&1) b.emplace_back(a[i]);
			else       c.emplace_back(a[i]);
		}
		sort(b.begin(),b.end());

		lint tmp_mx=0,tmp_mn=0;
		rep(i,b.size()){
			tmp_mx=10*tmp_mx+b[b.size()-1-i];
			tmp_mn=10*tmp_mn+b[i];
		}

		if(plus==0 && minus==0){
			mx=max(mx,tmp_mx);
			mn=min(mn,tmp_mn);
		}
		else{
			if(plus>0){
				auto t=dfs(c,plus-1,minus);
				mx=max(mx,t.first+tmp_mx);
				mn=min(mn,t.second+tmp_mn);
			}
			if(minus>0){
				auto t=dfs(c,plus,minus-1);
				mx=max(mx,t.first-tmp_mn);
				mn=min(mn,t.second-tmp_mx);
			}
		}
	}
	return memo[plus][minus][a]={mx,mn};
}

int main(){
	int n; scanf("%d",&n);
	vector<int> a;
	int plus=0,minus=0;
	rep(i,n){
		char c; scanf(" %c",&c);
		if(isdigit(c)) a.emplace_back(c-'0');
		else if(c=='+') plus++;
		else            minus++;
	}

	sort(a.begin(),a.end());

	auto ans=dfs(a,plus,minus);
	printf("%lld %lld\n",ans.first,ans.second);

	return 0;
}
