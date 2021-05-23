#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x1,y1,x2,y2; scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

	int ans=max(x1,y1);
	if(x1==y1 && x2==y2 && 0<x2 && x2<x1) ans++;
	printf("%d\n",ans);

	return 0;
}
