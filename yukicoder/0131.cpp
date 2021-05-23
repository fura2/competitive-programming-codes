#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x,y,d; scanf("%d%d%d",&x,&y,&d);
	if(x>y) swap(x,y);
	printf("%d\n",d<=x?d+1:d<=y?x+1:max(x+y-d+1,0));
	return 0;
}
