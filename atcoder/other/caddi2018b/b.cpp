#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,h,w; scanf("%d%d%d",&n,&h,&w);

	int ans=0;
	rep(i,n){
		int a,b; scanf("%d%d",&a,&b);
		if(a>=h && b>=w) ans++;
	}
	printf("%d\n",ans);

	return 0;
}
