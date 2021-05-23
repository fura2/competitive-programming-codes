#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k,q; scanf("%d%d%d",&n,&k,&q);
	vector<char> type(q);
	vector<int> pos(q),color(q);
	rep(i,q) scanf(" %c%d%d",&type[i],&pos[i],&color[i]), pos[i]--, color[i]--;

	vector<lint> ans(k);
	int rcnt=0,ccnt=0;
	set<int> R_used,C_used;
	for(int i=q-1;i>=0;i--){
		if(type[i]=='R'){
			if(R_used.count(pos[i])>0) continue;
			ans[color[i]]+=n-ccnt;
			rcnt++;
			R_used.emplace(pos[i]);
		}
		else{
			if(C_used.count(pos[i])>0) continue;
			ans[color[i]]+=n-rcnt;
			ccnt++;
			C_used.emplace(pos[i]);
		}
	}
	ans[0]+=1LL*n*n-accumulate(ans.begin(),ans.end(),0LL);

	rep(i,k) printf("%lld\n",ans[i]);

	return 0;
}
