#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n;
string B[6];

int dfs(int i,int j){
	if(i==n){
		vector<int> cnt(n);
		rep(i,n) rep(j,n) if(B[i][j]=='o') cnt[i]++;
		int res=1;
		for(int x=n-1;x>cnt[0];x--) if(count(cnt.begin(),cnt.end(),x)>0) res++;
		return res;
	}

	if(j==n) return dfs(i+1,0);
	if(B[i][j]!='-') return dfs(i,j+1);

	int res=n;
	B[i][j]='o'; B[j][i]='x';
	res=min(res,dfs(i,j+1));
	B[i][j]='x'; B[j][i]='o';
	res=min(res,dfs(i,j+1));
	B[i][j]='-'; B[j][i]='-';
	return res;
}

int main(){
	cin>>n;
	rep(i,n) cin>>B[i];

	cout<<dfs(0,0)<<'\n';

	return 0;
}
