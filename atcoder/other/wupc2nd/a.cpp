#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	int k=0;
	rep(i,n) k+=(i+1)*(i+1);
	printf("%d\n",k%m);
	return 0;
}
