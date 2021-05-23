#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	puts(n%2==1||k>=n/2?"first":"second");
	return 0;
}

// experiment
/*
bool dfs(vector<int> a,int k){
	int n=a.size();
	vector<int> b;
	rep(i,n) if(a[i]==0) {
		b=a;
		rep(j,n) if(b[j]==2) b[j]=0;
		b[i]=1;
		rep(j,n) if(b[j]==0 && abs(i-j)<=k) b[j]=2;
		if(!dfs(b,k)) return true;
	}
	return false;
}

int main(){
	for(int n=1;n<15;n++){
		rep(k,n+1){
			vector<int> a(n);
			bool res=dfs(a,k);
			printf("%c ",res?'o':'x');
		}
		puts("");
	}
	return 0;
}
*/
