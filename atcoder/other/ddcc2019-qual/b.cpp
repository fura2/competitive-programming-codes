#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	auto check=[&](int i,int j){
		return n<=2*(i+j) && 2*(i+j)<=3*n && -n<=2*(i-j) && 2*(i-j)<=n;
	};

	int ans=0;
	rep(i,n) rep(j,n) if(check(i,j) && check(i+1,j) && check(i,j+1) && check(i+1,j+1)) ans++;
	printf("%d\n",ans);

	return 0;
}
