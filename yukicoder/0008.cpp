#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int q; scanf("%d",&q);
	rep(_,q){
		int n,k; scanf("%d%d",&n,&k);
		puts((n-1)%(k+1)!=0?"Win":"Lose");
	}
	return 0;
}
