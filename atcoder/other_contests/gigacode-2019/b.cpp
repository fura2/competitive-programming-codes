#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,x,y,z; scanf("%d%d%d%d",&n,&x,&y,&z);

	int ans=0;
	rep(i,n){
		int a,b; scanf("%d%d",&a,&b);
		if(x<=a && y<=b && z<=a+b) ans++;
	}
	printf("%d\n",ans);

	return 0;
}
