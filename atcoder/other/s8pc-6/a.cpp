#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,T; scanf("%d%d",&n,&T);

	int sum=0;
	rep(i,n-1){
		int a; scanf("%d",&a);
		sum+=a;
	}
	printf("%d\n",(sum+T-1)/T);

	return 0;
}
