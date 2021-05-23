#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	const int M=1e5;

	int d,n;
	lint L; scanf("%d%lld%d",&d,&L,&n);
	vector<int> a(d);
	rep(i,d) scanf("%d",&a[i]), a[i]--;

	// pos[id] = 料理 id が提供される日のリスト
	vector<vector<int>> pos(M);
	rep(i,d){
		pos[a[i]].emplace_back(i);
		pos[a[i]].emplace_back(i+d);
	}
	rep(id,M) sort(pos[id].begin(),pos[id].end());

	// cnt[id][x] = 料理 id が好きな人が, pos[id][0] 日目から pos[id][x]-1 日目までに料理を食べる回数
	vector<vector<lint>> cnt(M);
	// per[id] = 料理 id が好きな人が, pos[id][0] 日目から初めて d 日間で料理を食べる回数
	vector<lint> per(M);
	rep(id,M) if(!pos[id].empty()) {
		cnt[id].assign(pos[id].size(),0);
		rep(x,pos[id].size()-1){
			cnt[id][x+1]=cnt[id][x]+(pos[id][x+1]-pos[id][x]+L-1)/L;
		}
		per[id]=cnt[id][pos[id].size()/2];
	}

	rep(i,n){
		int id,t0;
		lint T; scanf("%d%d%lld",&id,&t0,&T); id--; t0--;

		if(pos[id].empty()){
			puts("0");
			continue;
		}

		// 料理 id が提供される直近の日まで進む
		int x=lower_bound(pos[id].begin(),pos[id].end(),t0)-pos[id].begin();
		T-=(pos[id][x]-t0+L-1)/L;
		if(T<=0){
			puts("0");
			continue;
		}

		lint ans=T/per[id]*(pos[id].size()/2);
		T%=per[id];
		x%=pos[id].size()/2;
		int y=lower_bound(cnt[id].begin(),cnt[id].end(),cnt[id][x]+T)-cnt[id].begin();
		ans+=y-x;
		printf("%lld\n",ans);
	}

	return 0;
}
