#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	int ans;
	if(k==0 || k>n) ans=0;
	else if(n%2==1 && k==n/2+1) ans=n-1;
	else ans=n-2;
	printf("%d\n",ans);
	return 0;
}
