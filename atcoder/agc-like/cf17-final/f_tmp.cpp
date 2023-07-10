#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

// experiment
/*
int n,k;
int res[1060][1060],cnt[1060];

bool dfs(int i,int j,int pre){
	rep(y1,i){
		bool f[1060]={};
		rep(x1,k) f[res[y1][x1]]=true;

		for(int y2=y1+1;y2<i;y2++) {
			int c=0;
			rep(x2,k) if(f[res[y2][x2]]) c++;
			if(c!=1) return false;
		}
	}

	if(i==n){
		rep(y,n){
			rep(x,k) printf("%2d ",res[y][x]+1);
			puts("");
		}
		return true;
	}

	if(j==k) return dfs(i+1,0,-1);

	for(int a=pre+1;a<n;a++) if(cnt[a]<k) {
		cnt[a]++;
		res[i][j]=a;
		if(dfs(i,j+1,a)) return true;
		cnt[a]--;
	}
	return false;
}

int main(){
	scanf("%d%d",&n,&k);
	printf("n = %d, k = %d\n",n,k);

	rep(i,n) cnt[i]=0;
	rep(j,k) res[0][j]=j, cnt[j]++;
	dfs(1,0,-1);

	return 0;
}
*/

int main(){
	int k=5;
	int n=k*k-k+1;

	int res[2060][63];
	rep(i,n) rep(j,k) res[i][j]=-1;
	// res[0]
	rep(i,k){
		res[i][0]=1;
		rep(j,k-1) res[i][j+1]=i*(k-1)+j+2;
	}
	// res[i][0] (i=1,2,...,n-1)
	{
		int idx=k;
		for(int i=2;i<=k;i++) rep(j,k-1) res[idx++][0]=i;
	}
	// res[i][j] (i=1,2,...,n-1; j=0,1,...,k-1)
	for(int i=k;i<n;i++){
		vector<int> a; // res[i] と res[i'] が共通する数をもつような i' (< i) の全体
		for(int j=1;j<k;j++){
			rep(y,i) if(res[i][j-1]==res[y][j-1]) a.emplace_back(y);

			set<int> S;
			for(int idx:a) S.emplace(res[idx][j]);

			rep(l,k-1){
				int num=j*(k-1)+l+2;
				if(S.count(num)==0){
					res[i][j]=num;
					break;
				}
			}
		}
	}

	printf("%d %d\n",n,k);
	rep(i,n) rep(j,k) printf("%2d%c",res[i][j],j<k-1?' ':'\n');

	return 0;
}
