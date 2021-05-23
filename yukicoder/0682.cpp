#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; scanf("%d%d",&a,&b);
	int ans=0;
	for(int i=a;i<=b;i++) if((a+b+i)%3==0) ans++;
	printf("%d\n",ans);
	return 0;
}
