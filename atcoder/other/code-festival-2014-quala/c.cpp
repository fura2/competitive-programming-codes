#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int f(int n){ return n/4-n/100+n/400; }

int main(){
	int a,b; scanf("%d%d",&a,&b);
	printf("%d\n",f(b)-f(a-1));
	return 0;
}
