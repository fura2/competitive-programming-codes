#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int ans=0;
	static bool f[20001][20001];
	rep(i,n){
		int x,y; scanf("%d%d",&x,&y);
		bool ok=true;
		for(int y2=max(y-20,0);y2<=min(y+20,20000);y2++){
			for(int x2=max(x-20,0);x2<=min(x+20,20000);x2++){
				if(f[y2][x2] && (x-x2)*(x-x2)+(y-y2)*(y-y2)<400){
					ok=false;
				}
			}
		}
		if(ok) f[y][x]=true, ans++;
	}
	printf("%d\n",ans);

	return 0;
}
