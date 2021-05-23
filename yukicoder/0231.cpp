#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int mx=0,imx=-1;
	rep(i,n){
		int a,b; scanf("%d%d",&a,&b);
		if(mx<a-30000*b){
			mx=a-30000*b;
			imx=i;
		}
	}

	if(6*mx>=3000000){
		puts("YES");
		rep(i,6) printf("%d\n",imx+1);
	}
	else puts("NO");

	return 0;
}
