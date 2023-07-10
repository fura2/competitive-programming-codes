#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<vector<int>> S(m);
	rep(i,n){
		S[a[i]%m].emplace_back(a[i]);
	}
	rep(i,m) sort(S[i].begin(),S[i].end());

	int ans=S[0].size()/2;
	if(m%2==0) ans+=S[m/2].size()/2;
	for(int i=1;i<=(m-1)/2;i++){
		int sz1=S[i].size(),sz2=S[m-i].size();
		if(sz1>=sz2){
			int dup=0;
			rep(j,sz1) if(j+1<sz1 && S[i][j]==S[i][j+1]) dup++, j++;
			ans+=sz2;
			ans+=min(dup,(sz1-sz2)/2);
		}
		else{
			int dup=0;
			rep(j,sz2) if(j+1<sz2 && S[m-i][j]==S[m-i][j+1]) dup++, j++;
			ans+=sz1;
			ans+=min(dup,(sz2-sz1)/2);
		}
	}
	printf("%d\n",ans);

	return 0;
}
