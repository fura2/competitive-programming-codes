#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;

	if(n%2==0) return puts("No"),0;

	int ans[1000][1000];
	for(int j=1;j<n;j++) rep(i,n-1)  ans[i][j]=(i+2>j?i:i+1);
	rep(j,n) ans[n-1][j]=n-1;

	int cnt[1000]={1};
	rep(i,n) rep(j,n) ans[i][j]+=n*(cnt[ans[i][j]]++);

	puts("Yes");
	rep(i,n) rep(j,n) printf("%d%c",ans[i][j],j<n-1?' ':'\n');

	return 0;
}
