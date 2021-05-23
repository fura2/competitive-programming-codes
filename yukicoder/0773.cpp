#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; scanf("%d%d",&a,&b);
	int ans=3;
	for(int i=23;i<=25;i++) if(a<=i && i<=b) ans--;
	printf("%d\n",ans);
	return 0;
}
