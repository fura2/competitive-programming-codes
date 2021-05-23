#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k,x; scanf("%d%d%d",&n,&k,&x); x--;
	vector<int> s(n),g(n);
	iota(s.begin(),s.end(),0);
	vector<int> a(k),b(k);
	rep(i,k){
		if(i!=x) scanf("%d%d",&a[i],&b[i]), a[i]--, b[i]--;
		else     scanf("%*s%*s");
	}
	rep(i,n) scanf("%d",&g[i]), g[i]--;

	rep(i,x) swap(s[a[i]],s[b[i]]);
	for(int i=k-1;i>x;i--) swap(g[a[i]],g[b[i]]);

	vector<int> ans;
	rep(i,n) if(s[i]!=g[i]) ans.emplace_back(i);
	printf("%d %d\n",ans[0]+1,ans[1]+1);

	return 0;
}
