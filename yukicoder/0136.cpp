#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);

	int ans=0;
	for(int i=1;i<n;i++) if(n%i==0) ans=i;
	printf("%d\n",ans);

	return 0;
}
