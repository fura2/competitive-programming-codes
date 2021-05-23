#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int a=1;
	for(int i=2;i*i<=n;i++) if(n%(i*i)==0) a*=i, n/=i*i, i--;
	printf("%d %d\n",a,n);
	return 0;
}
