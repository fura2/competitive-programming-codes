#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int ans=INT_MAX;
	rep(i,n){
		int a,b; scanf("%d%d",&a,&b);
		ans=min(ans,a+b);
	}
	printf("%d\n",ans);
	return 0;
}
