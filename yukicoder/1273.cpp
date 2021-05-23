#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x; scanf("%d",&x);

	if(x==2){
		puts("1000000");
		return 0;
	}

	double ans=0;
	for(int i=2;i<1e6;i++){
		ans+=1.0/(pow(i,x-1)*(i-1));
	}
	printf("%d\n",int(ans*1e6));

	return 0;
}
