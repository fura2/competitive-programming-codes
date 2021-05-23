#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; scanf("%d%d",&a,&b);
	printf("%d\n",50*a+int(50*a/(0.8+0.2*b)+1e-8));
	return 0;
}
