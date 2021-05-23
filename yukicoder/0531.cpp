#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	if(m>=n) puts("1");
	else if(n%2==0 && 2*m>=n) puts("2");
	else puts("-1");
	return 0;
}
