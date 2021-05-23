#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int l,r,m; scanf("%d%d%d",&l,&r,&m);
	printf("%d\n",min((r-l+1),m));
	return 0;
}
