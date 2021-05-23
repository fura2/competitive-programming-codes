#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,d; scanf("%d%d",&n,&d);
	printf("%d\n",n/gcd(n,d)-1);
	return 0;
}
