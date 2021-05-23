#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x,y; scanf("%d%d",&x,&y);
	int ans;
	for(ans=1;ans*ans<=4*(x*x+y*y);ans++);
	printf("%d\n",ans);
	return 0;
}
