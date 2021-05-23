#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int p; scanf("%d",&p);

	if(p==1){
		puts("1");
		return 0;
	}

	vector<int> F(6*p+1);
	F[0]=0;
	F[1]=1;
	for(int i=2;i<=6*p;i++){
		F[i]=(F[i-1]+F[i-2])%p;
		if(F[i]==0){
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1");

	return 0;
}
