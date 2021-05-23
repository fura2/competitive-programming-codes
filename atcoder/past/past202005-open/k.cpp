#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,q; scanf("%d%d",&n,&q);

	// prev[i] = (コンテナ i の 1 つ下にあるコンテナの番号 (コンテナがなければ -1))
	vector<int> prev(n,-1);

	// top[i] = (机 i の一番上に置かれているコンテナの番号 (コンテナがなければ -1))
	vector<int> top(n);
	iota(top.begin(),top.end(),0);

	rep(_,q){
		int from,to,x; scanf("%d%d%d",&from,&to,&x); from--; to--; x--;
		tie(prev[x],top[to],top[from])=make_tuple(top[to],top[from],prev[x]);
	}

	vector<int> ans(n);
	rep(i,n){
		for(int x=top[i];x!=-1;x=prev[x]){
			ans[x]=i;
		}
	}
	rep(i,n) printf("%d\n",ans[i]+1);

	return 0;
}
