#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int m,n; scanf("%d%d",&m,&n);

	int ans=0;
	rep(i,m){
		int cnt=0;
		rep(j,n){
			int a; scanf("%d",&a);
			cnt+=a;
		}
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);

	return 0;
}
