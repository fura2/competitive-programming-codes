#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int cnt[11]={};
	rep(i,n) rep(j,3) {
		int a; scanf("%d",&a);
		cnt[a]++;
	}

	int ans=0,sum=0;
	rep(x,11) ans+=cnt[x]/2, sum+=cnt[x]%2;
	ans+=sum/4;
	printf("%d\n",ans);

	return 0;
}
