#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int ans=0;
	rep(a,n+1) rep(b,a+1) rep(c,n+1) if(5*a+2*b+3*c==n) ans++;
	printf("%d\n",ans);
	return 0;
}
