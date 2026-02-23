#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,T; scanf("%d%d%d",&n,&m,&T);

	vector<int> a(T);
	rep(i,n){
		int t,k; scanf("%d%d",&t,&k); t--;
		for(int j=t;j<T;j++) a[j]+=k;
	}

	int ans=0;
	rep(j,T-1) if(a[j]>=m) ans++;
	printf("%d\n",ans);

	return 0;
}
