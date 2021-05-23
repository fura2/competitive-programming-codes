#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int ans=0;
	rep(S,1<<n){
		int tmp=0;
		rep(i,n) if(S>>i&1) tmp+=a[i];
		if(tmp<=k) ans=max(ans,tmp);
	}
	printf("%d\n",ans);

	return 0;
}
