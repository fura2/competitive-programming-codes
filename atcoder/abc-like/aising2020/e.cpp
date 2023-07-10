#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint solve(vector<pair<int,int>> a){
	sort(a.begin(),a.end());

	lint ans=0;
	priority_queue<int,vector<int>,greater<>> Q;
	for(auto [k,d]:a){
		Q.emplace(d);
		ans+=d;
		while(Q.size()>k) ans-=Q.top(), Q.pop();
	}
	return ans;
}

int main(){
	int q; scanf("%d",&q);
	rep(_,q){
		int n; scanf("%d",&n);
		lint sum=0;
		vector<pair<int,int>> L,R;
		rep(i,n){
			int k,l,r; scanf("%d%d%d",&k,&l,&r);
			if     (l>r) L.emplace_back( k ,l-r), sum+=r;
			else if(r>l) R.emplace_back(n-k,r-l), sum+=l;
			else         sum+=l;
		}
		printf("%lld\n",sum+solve(L)+solve(R));
	}

	return 0;
}
