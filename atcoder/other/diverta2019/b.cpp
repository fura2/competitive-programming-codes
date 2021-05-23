#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int r,g,b,n; scanf("%d%d%d%d",&r,&g,&b,&n);

	int ans=0;
	rep(i,n+1) rep(j,n+1) {
		int m=n-(i*r+j*b);
		if(m>=0 && m%g==0) ans++;
	}
	printf("%d\n",ans);

	return 0;
}
