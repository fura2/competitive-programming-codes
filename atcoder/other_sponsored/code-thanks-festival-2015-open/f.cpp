#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int cnt=0;
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		if(u==0 || v==0) cnt++;
	}

	puts(cnt==1||n%2==0?"A":"B");

	return 0;
}
