#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,na,nb,nc,nd,a[100],b[100],c[100],d[100];

char memo[101][101][101][101];
vector<int> ans;

bool dfs(int t,int i,int j,int k,int l){
	char& res=memo[i][j][k][l];
	if(res!=-1) return res;

	if(t==n){
		return res=(i==na && j==nb && k==nc && l==nd);
	}

	// a が 4 位
	int S=0;
	if(j<nb) S|=1<<b[j];
	if(k<nc) S|=1<<c[k];
	if(l<nd) S|=1<<d[l];
	if(S==7){
		if(dfs(t+1,i,min(j+1,nb),min(k+1,nc),min(l+1,nd))){
			ans.emplace_back(0);
			return res=true;
		}
	}
	// b が 4 位
	S=0;
	if(i<na) S|=1<<a[i];
	if(k<nc) S|=1<<c[k];
	if(l<nd) S|=1<<d[l];
	if(S==7){
		if(dfs(t+1,min(i+1,na),j,min(k+1,nc),min(l+1,nd))){
			ans.emplace_back(1);
			return res=true;
		}
	}
	// c が 4 位
	S=0;
	if(i<na) S|=1<<a[i];
	if(j<nb) S|=1<<b[j];
	if(l<nd) S|=1<<d[l];
	if(S==7){
		if(dfs(t+1,min(i+1,na),min(j+1,nb),k,min(l+1,nd))){
			ans.emplace_back(2);
			return res=true;
		}
	}
	// d が 4 位
	S=0;
	if(i<na) S|=1<<a[i];
	if(j<nb) S|=1<<b[j];
	if(k<nc) S|=1<<c[k];
	if(S==7){
		if(dfs(t+1,min(i+1,na),min(j+1,nb),min(k+1,nc),l)){
			ans.emplace_back(3);
			return res=true;
		}
	}
	return res=false;
}

int main(){
	scanf("%d%d%d%d%d",&n,&na,&nb,&nc,&nd);
	rep(i,na) scanf("%d",&a[i]), a[i]--;
	rep(i,nb) scanf("%d",&b[i]), b[i]--;
	rep(i,nc) scanf("%d",&c[i]), c[i]--;
	rep(i,nd) scanf("%d",&d[i]), d[i]--;

	memset(memo,-1,sizeof memo);
	if(!dfs(0,0,0,0,0)){
		puts("No");
	}
	else{
		puts("Yes");
		for(int i=ans.size()-1;i>=0;i--) printf("%d\n",ans[i]+1);
	}

	return 0;
}
