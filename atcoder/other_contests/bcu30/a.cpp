#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);

	int x=0;
	rep(i,k){
		int a; scanf("%d",&a);
		x+=a;
		if(x>n){
			x=n-(x-n);
		}
		if(x==n){
			break;
		}
	}
	printf("%d\n",x);

	return 0;
}
