#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int p,q,n; scanf("%d%d%d",&p,&q,&n);

	int ans=0;
	rep(_,n){
		int x,y; scanf("%d%d",&x,&y);

		if(p==0 && q==0){
			if(x==0 && y==0) ans++;
			continue;
		}

		int g=gcd(p,q);
		if(x%g!=0 || y%g!=0) continue;

		if((p/g+q/g)%2==1 || (x/g+y/g)%2==0) ans++;
	}
	printf("%d\n",ans);

	return 0;
}
