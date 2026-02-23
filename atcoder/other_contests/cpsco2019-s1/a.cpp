#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a; scanf("%d%d",&n,&a);
	printf("%d %d\n",(a+2)/3,min(a,n/3));
	return 0;
}
