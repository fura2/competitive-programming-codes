#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x; scanf("%d",&x);
	rep(k,1001) if(x-100*k>=0 && (x-100*k+4)/5<=k) return puts("1"),0;
	puts("0");
	return 0;
}
