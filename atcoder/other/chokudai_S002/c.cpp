#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int ans=0;
	rep(i,n){
		int a,b; scanf("%d%d",&a,&b);
		ans=max(ans,a+b);
	}
	printf("%d\n",ans);
	return 0;
}
