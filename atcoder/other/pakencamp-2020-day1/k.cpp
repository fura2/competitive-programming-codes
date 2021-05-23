#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> cum(n+1);
	rep(i,n) cum[i+1]=cum[i]+a[i];

	vector<int> ans(n+1);
	for(int x=1;x<=cum[n];x++){
		if(cum[n]%x!=0) continue;

		int cnt=0,pre=0;
		rep(i,n){
			if((cum[i+1]-cum[pre])%x==0){
				cnt++;
				pre=i+1;
			}
		}
		for(int i=1;i<=cnt;i++) ans[i]=max(ans[i],x);
	}

	rep(i,n) printf("%d\n",ans[i+1]);

	return 0;
}
