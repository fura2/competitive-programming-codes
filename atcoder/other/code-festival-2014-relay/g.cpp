#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	bool dp[20001]={true};
	rep(i,n){
		int a; scanf("%d",&a);
		for(int w=20000;w>=a;w--) dp[w]|=dp[w-a];
	}

	int w;
	for(w=m;w<=20000&&!dp[w];w++);
	printf("%d\n",w<=20000?w:-1);

	return 0;
}
