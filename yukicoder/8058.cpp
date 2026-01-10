#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int m,d; scanf("%d%d",&m,&d);
	printf("%d\n",m==4&&d==1?m-d:m+d);
	return 0;
}
