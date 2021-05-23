#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int n,k,a[32];

int dfs(int i,int cnt,int sum){
	if(cnt==k){
		int res=0;
		for(char c:to_string(sum)){
			if(c>='5') res++, c-=5;
			res+=c-'0';
		}
		return res;
	}
	if(i==n) return INF;

	return min(dfs(i+1,cnt,sum),dfs(i+1,cnt+1,sum+a[i]));
}

int main(){
	scanf("%d%d",&n,&k);
	rep(i,n) scanf("%d",&a[i]);

	printf("%d\n",dfs(0,0,0));

	return 0;
}
