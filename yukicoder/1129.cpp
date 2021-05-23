#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
	if     (a!=c) puts(a>c?"null":"tRue");
	else if(b!=d) puts((b+1)%3==d?"null":"tRue");
	else          puts("Draw");
	return 0;
}
