#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);

	int ans;
	if(n%2==0) ans=min(k+1,n/2);
	else       ans=min(k+1,n);
	printf("%d\n",ans);

	return 0;
}
