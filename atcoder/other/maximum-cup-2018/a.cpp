#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int ans=0;
	rep(i,n){
		int t,x,m; scanf("%d%d%d",&t,&x,&m);
		if(t+10<=x) ans+=m;
	}
	printf("%d\n",ans);

	return 0;
}
