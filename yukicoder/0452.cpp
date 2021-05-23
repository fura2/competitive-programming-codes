#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector B(m,vector(n,vector(n,0)));
	rep(i,m) rep(x,n) rep(y,n) scanf("%d",&B[i][x][y]);

	vector seq(m,vector<vector<int>>());
	rep(i,m){
		vector<int> tmp(n);
		rep(x,n){
			rep(y,n) tmp[y]=B[i][x][y];
			seq[i].emplace_back(tmp);
		}
		rep(y,n){
			rep(x,n) tmp[x]=B[i][x][y];
			seq[i].emplace_back(tmp);
		}
		{
			rep(x,n) tmp[x]=B[i][x][x];
			seq[i].emplace_back(tmp);
			rep(x,n) tmp[x]=B[i][x][n-1-x];
			seq[i].emplace_back(tmp);
		}
		for(auto& a:seq[i]) sort(a.begin(),a.end());
	}

	int ans=2*n;
	rep(i,m) for(int j=i+1;j<m;j++) {
		for(const auto& a:seq[i]) for(const auto& b:seq[j]) {
			int idx1=0,idx2=0,cnt=0;
			while(idx1<n || idx2<n){
				if(idx1==n){
					cnt+=n-idx2;
					break;
				}
				if(idx2==n){
					cnt+=n-idx1;
					break;
				}
				if(a[idx1]==b[idx2]){
					idx1++;
					idx2++;
					cnt++;
				}
				else if(a[idx1]<b[idx2]){
					idx1++;
					cnt++;
				}
				else{
					idx2++;
					cnt++;
				}
			}
			ans=min(ans,cnt-1);
		}
	}
	printf("%d\n",ans);

	return 0;
}
