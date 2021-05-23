#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k,s; scanf("%d%d%d",&n,&k,&s);

	int ans[100000];
	rep(i,n){
		if(i<k) ans[i]=s;
		else    ans[i]=(s==1000000000?s-1:1000000000);
	}

	rep(i,n) printf("%d%c",ans[i],i<n-1?' ':'\n');

	return 0;
}
