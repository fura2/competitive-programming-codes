#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int sum[2]={};
	rep(i,2) rep(j,4) {
		int a; scanf("%d",&a);
		sum[i]+=a;
	}
	printf("%d\n",max(sum[0],sum[1]));
	return 0;
}
