#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	printf("0%s",n>0?".":"");
	rep(i,n) putchar("142857"[i%6]);
	puts("");
	return 0;
}
