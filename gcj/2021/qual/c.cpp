#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int tst; scanf("%d",&tst);
	rep(_,tst){
		printf("Case #%d: ",_+1);

		int n,c; scanf("%d%d",&n,&c);
		c-=n-1;

		if(c<0 || n*(n-1)/2<c){
			puts("IMPOSSIBLE");
			continue;
		}

		vector<int> r(n-1);
		rep(i,n-1){
			r[i]=min(n-1-i,c);
			c-=r[i];
		}

		vector<int> ans(n);
		ans[n-1]=n-1;
		for(int i=n-2;i>=0;i--){
			ans[i]=i;
			reverse(ans.begin()+i,ans.begin()+i+r[i]+1);
		}
		rep(i,n) printf("%d%c",ans[i]+1,i<n-1?' ':'\n');
	}

	return 0;
}
