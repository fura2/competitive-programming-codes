#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<vector<int>> a(n,vector<int>(m));
	rep(i,n) rep(j,m) scanf("%d",&a[i][j]);

	int ans=0;
	vector<int> cnt(n),mx(m);
	vector<vector<int>> L(m);
	rep(i,n){
		rep(j,m){
			if(a[i][j]>mx[j]){
				mx[j]=a[i][j];
				for(int k:L[j]){
					cnt[k]--;
					if(cnt[k]==0) ans--;
				}
				L[j].clear();
			}
			if(a[i][j]==mx[j]){
				L[j].emplace_back(i);
				cnt[i]++;
			}
		}
		if(cnt[i]>0) ans++;
		printf("%d\n",ans);
	}

	return 0;
}
