#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; scanf("%d%d",&a,&b);
	if(b%a==0) printf("%d\n",b/a);
	else puts("NO");
	return 0;
}
