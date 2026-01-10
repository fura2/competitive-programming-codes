#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,x; scanf("%d%d%d",&n,&m,&x);
	puts(x-(n-m)>=3?"YES":"NO");
	return 0;
}
