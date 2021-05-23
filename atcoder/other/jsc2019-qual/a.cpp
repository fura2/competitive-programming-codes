#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int m,d; scanf("%d%d",&m,&d);
	int ans=0;
	for(;d>0;d--) if(d/10>=2 && d%10>=2 && (d/10)*(d%10)<=m) ans++;
	printf("%d\n",ans);
	return 0;
}
