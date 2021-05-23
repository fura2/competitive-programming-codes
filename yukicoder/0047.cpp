#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,i; scanf("%d",&n);
	for(i=0;(1<<i)<n;i++);
	printf("%d\n",i);
	return 0;
}
