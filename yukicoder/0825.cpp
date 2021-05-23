#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int a,b,c; scanf("%d%d%d",&a,&b,&c);
	int ans=INF;
	for(int i=1;i<=a+10*b;i++){
		rep(x,a+1) rep(y,b+1) if(x+10*y>=i) {
			int g=x+10*y-i;
			int z=(a-x)+(b-y)+g/10+g%10;
			if(z==c) ans=min(ans,i);
		}
	}
	if(ans<INF) printf("%d\n",ans);
	else puts("Impossible");
	return 0;
}
