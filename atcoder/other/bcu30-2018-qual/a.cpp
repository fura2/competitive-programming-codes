#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int ans[30]={};
	rep(i,n){
		int a; scanf("%d",&a);
		ans[a]++;
	}
	rep(i,30) printf("%d%c",ans[i],i<29?' ':'\n');

	return 0;
}
