#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	if(k==1){
		printf("%d\n",(1<<(n-k))-n);
	}else{
		printf("%d\n",1<<(n-k));
	}
	return 0;
}
