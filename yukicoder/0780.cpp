#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; scanf("%d%d",&a,&b);
	a++;
	printf("%s\n%d\n",a<=b?"YES":"NO",abs(a-b));
	return 0;
}
