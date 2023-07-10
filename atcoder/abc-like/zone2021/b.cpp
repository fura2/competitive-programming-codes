#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,d,h; scanf("%d%d%d",&n,&d,&h);

	double ans=0;
	rep(i,n){
		int x,y; scanf("%d%d",&x,&y);
		ans=max(ans,y-double(h-y)/(d-x)*x);
	}
	printf("%.9f\n",ans);

	return 0;
}
