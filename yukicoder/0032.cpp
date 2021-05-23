#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int l,m,n; scanf("%d%d%d",&l,&m,&n);
	int total=100*l+25*m+n;
	total%=1000;

	int ans=0;
	ans+=total/100;
	total%=100;
	ans+=total/25;
	total%=25;
	ans+=total;
	printf("%d\n",ans);

	return 0;
}
