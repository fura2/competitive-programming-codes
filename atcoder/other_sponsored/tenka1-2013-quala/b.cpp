#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int ans=0;
	rep(i,n){
		int sum=0;
		rep(j,5){ int a; scanf("%d",&a); sum+=a; }
		if(sum<20) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
