#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);

	int p=0;
	if((n-1)%(k+1)==0){ // 後攻
		puts("0");
		fflush(stdout);
		scanf("%d",&p);
	}

	while(p<n){
		p+=(n-1-p)%(k+1);
		printf("%d\n",p);
		fflush(stdout);
		scanf("%d",&p);
	}

	return 0;
}
