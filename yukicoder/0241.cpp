#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

random_device seed_gen;
mt19937 rng(seed_gen());

int main(){
	int n; scanf("%d",&n);
	vector<int> ng(n);
	rep(i,n) scanf("%d",&ng[i]);

	if(ng[0]<n && count(ng.begin(),ng.end(),ng[0])==n) return puts("-1"),0;

	vector<int> ans(n);
	iota(ans.begin(),ans.end(),0);
	while(1){
		bool ok=true;
		rep(i,n) if(ans[i]==ng[i]) ok=false;
		if(ok) break;
		shuffle(ans.begin(),ans.end(),rng);
	}
	rep(i,n) printf("%d\n",ans[i]);

	return 0;
}
