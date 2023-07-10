#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a,b; scanf("%d%d%d",&n,&a,&b);
	printf("%d %d\n",min(a,b),max(a+b-n,0));
	return 0;
}
