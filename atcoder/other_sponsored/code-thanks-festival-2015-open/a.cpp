#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; scanf("%d%d",&a,&b);
	printf("%d\n",abs(a)+abs(a-b)+abs(b));
	return 0;
}
