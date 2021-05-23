#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,q; scanf("%d%d",&n,&q);
	rep(_,q){
		int a,b; scanf("%d%d",&a,&b);
		int res=min({a,n-a+1,b,n-b+1})%3;
		printf("%d\n",res==0?3:res);
	}
	return 0;
}
