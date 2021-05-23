#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x,y,r; scanf("%d%d%d",&x,&y,&r);
	printf("%d\n",int(abs(x)+abs(y)+sqrt(2)*r)+1);
	return 0;
}
