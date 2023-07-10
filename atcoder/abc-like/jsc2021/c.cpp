#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; scanf("%d%d",&a,&b);

	int ans=1;
	for(int d=2;d<=b;d++){
		if(b/d-(a-1)/d>=2) ans=d;
	}
	printf("%d\n",ans);

	return 0;
}
