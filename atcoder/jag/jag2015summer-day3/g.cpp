#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	// coordinate compression
	vector<int> X=a;
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	rep(i,n) a[i]=lower_bound(X.begin(),X.end(),a[i])-X.begin();

	int m=X.size();
	vector<vector<int>> Pos(m,vector<int>());
	rep(i,n) Pos[a[i]].emplace_back(i);

	// Pos[l..r] を丸々使うパターン
	int res1=0,pre=0,sum=Pos[0].size();
	for(int i=1;i<=m;i++){
		if(i==m || Pos[i-1].back()>Pos[i][0]){
			if(pre>0){
				sum+=lower_bound(Pos[pre-1].begin(),Pos[pre-1].end(),Pos[pre][0])-Pos[pre-1].begin();
			}
			if(i<m){
				sum+=Pos[i].end()-lower_bound(Pos[i].begin(),Pos[i].end(),Pos[i-1].back());
			}
			res1=max(res1,sum);

			pre=i;
			if(i<m) sum=Pos[i].size();
		}
		else{
			sum+=Pos[i].size();
		}
	}

	// Pos[i], Pos[i+1] を部分的に使うパターン (ex: 2 1 1 1 2 2 2 1)
	int res2=0;
	rep(i,m-1) rep(j,Pos[i].size()) {
		int tmp=Pos[i+1].end()-lower_bound(Pos[i+1].begin(),Pos[i+1].end(),Pos[i][j]);
		res2=max(res2,(j+1)+tmp);
	}

	printf("%d\n",n-max(res1,res2));

	return 0;
}
