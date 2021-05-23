#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

void solve(){
	int x,y; scanf("%d%d",&x,&y);

	int ans=0;
	for(int d=1;d*d<=x+y;d++) if((x+y)%d==0) {
		for(lint a:{d-1,(x+y)/d-1}) if(a>=2) {
			lint D=a*a-1;
			lint b=a*x-y,c=-x+a*y;
			if(b%D==0 && c%D==0){
				b/=D;
				c/=D;
				if(b>0 && c>0) ans++;
			}
		}
	}

	// a == 1
	if(x==y) ans+=x-1;

	printf("%d\n",ans);
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
