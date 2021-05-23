#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; scanf("%d%d",&a,&b);
	printf("%d\n",a<b?b-2:2000000000-b-1);
	return 0;
}
