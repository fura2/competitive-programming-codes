#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int n,m,a[10],b[10];

int used[10],ans;

void dfs(int i,int cnt){
	if(cnt>=ans) return;

	if(i==n){
		ans=cnt;
		return;
	}

	rep(j,m) if(used[j]+a[i]<=b[j]) {
		used[j]+=a[i];
		dfs(i+1,cnt+(used[j]==a[i]?1:0));
		used[j]-=a[i];
	}
}

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);
	scanf("%d",&m);
	rep(j,m) scanf("%d",&b[j]);

	sort(a,a+n,greater<int>());
	sort(b,b+m);

	ans=INF;
	dfs(0,0);
	printf("%d\n",ans<INF?ans:-1);

	return 0;
}
