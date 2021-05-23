#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x,y; scanf("%d%d",&x,&y);
	if     (x==y)   puts("0");
	else if(y==0)   puts("1");
	else if(x==0)   puts("2");
	else if(x+y==0) puts("3");
	else            puts("-1");
	return 0;
}
