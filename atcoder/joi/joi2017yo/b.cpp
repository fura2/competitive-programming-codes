#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(m),b(m);
	rep(i,m) scanf("%d%d",&a[i],&b[i]);

	int cnt=0;
	rep(i,m) if(a[i]>=n) cnt++;
	if(cnt>=m-1){
		puts("0");
		return 0;
	}

	int ans=0,a_min=a[0];
	rep(i,m){
		a_min=min(a_min,a[i]);
		if(a[i]<n) ans+=n-a[i];
	}
	ans-=n-a_min;
	printf("%d\n",ans);

	return 0;
}
