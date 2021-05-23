#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a,b; scanf("%d%d%d",&n,&a,&b);

	int ans=n;
	rep(i,n){
		int t; scanf("%d",&t);
		if(a<=t && t<b) ans--;
	}
	printf("%d\n",ans);

	return 0;
}
