#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,L; scanf("%d%d",&n,&L);
	vector<int> m(n);
	rep(i,n) scanf("%d",&m[i]);

	vector<queue<int>> S(n),T(n);
	rep(i,n) rep(j,m[i]){ int a; scanf("%d",&a); S[i].emplace(a); }
	rep(i,n) rep(j,m[i]){ int a; scanf("%d",&a); T[i].emplace(a); }

	vector<int> ans(n);
	while(1){
		int i_min=-1;
		rep(i,n) if(!S[i].empty() && (i_min==-1 || S[i].front()<S[i_min].front())) {
			i_min=i;
		}
		if(i_min==-1 || T[i_min].front()>L) break;

		ans[i_min]=S[i_min].front();
		S[i_min].pop();
		L-=T[i_min].front();
		T[i_min].pop();
	}

	printf("%d\n",accumulate(ans.begin(),ans.end(),0));

	return 0;
}
