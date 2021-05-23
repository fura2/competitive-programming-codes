#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	rep(x,n+1) if((int)(1.08*x)==n) return printf("%d\n",x),0;
	puts(":(");
	return 0;
}
