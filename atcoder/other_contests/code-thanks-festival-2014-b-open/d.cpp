#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,T; scanf("%d%d",&n,&T);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int ans=0;
	for(int t=1;t<=T;t++){
		int cnt=0;
		rep(i,n) if(t%a[i]==0) cnt++;
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);

	return 0;
}
