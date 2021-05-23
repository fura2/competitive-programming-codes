#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	rep(i,n){
		int a; scanf("%d",&a);
		if     (a%40==0) puts("ikisugi");
		else if(a% 8==0) puts("iki");
		else if(a%10==0) puts("sugi");
		else             printf("%d\n",a/3);
	}
	return 0;
}
