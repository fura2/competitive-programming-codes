#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int m,n; scanf("%d%d",&m,&n);
	printf("%d\n",m-m/n*(n-1));
	return 0;
}
