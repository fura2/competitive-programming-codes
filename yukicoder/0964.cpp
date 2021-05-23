#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	rep(i,n) rep(j,n) putchar('0'+(i+1)%10);
	putchar('\n');
	return 0;
}
