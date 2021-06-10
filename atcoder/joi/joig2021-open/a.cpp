#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c; scanf("%d%d%d",&a,&b,&c);
	printf("%d\n",3*max({a,b,c})-a-b-c);
	return 0;
}
