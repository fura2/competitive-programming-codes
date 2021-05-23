#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	int ans=0;
	rep(i,n){
		int a; scanf("%d",&a);
		ans^=a%(k+1);
	}
	puts(ans!=0?"YES":"NO");
	return 0;
}
