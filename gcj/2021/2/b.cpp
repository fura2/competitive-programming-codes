#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int N=1e6;
int a[N+1];

void solve(){
	int n; scanf("%d",&n);
	int ans=0;
	for(int d=3;d<=n;d++) if(n%d==0) ans=max(ans,a[(n-d)/d]+1);
	printf("%d\n",ans);
}

int main(){
	vector D(N,vector<int>());
	for(int i=2;i<=N;i++){
		for(int j=i;j<=N;j+=i){
			D[j].emplace_back(i);
		}
	}
	a[0]=a[1]=0;
	for(int i=2;i<=N;i++){
		for(int d:D[i]){
			a[i]=max(a[i],a[(i-d)/d]+1);
		}
	}

	int t; scanf("%d",&t);
	rep(_,t){
		printf("Case #%d: ",_+1);
		solve();
	}
	return 0;
}
