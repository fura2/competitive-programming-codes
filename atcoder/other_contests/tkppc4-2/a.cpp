#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x,y; scanf("%d%d",&x,&y);
	if(y<0 || y%2!=0) puts("-1");
	else{
		int m=y/2;
		if(abs(x)%2==m%2 && abs(x)<=m) printf("%d\n",m);
		else puts("-1");
	}
	return 0;
}
