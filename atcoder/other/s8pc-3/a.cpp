#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);

	int ans=0;
	rep(i,11){
		rep(j,5){
			int sum=0;
			rep(y,3) rep(x,3) sum+=7*(i+y)+(j+x+1);
			if(sum%11==k) ans++;
		}
	}
	ans*=(n-2)/11;
	rep(i,(n-2)%11){
		rep(j,5){
			int sum=0;
			rep(y,3) rep(x,3) sum+=7*(i+y)+(j+x+1);
			if(sum%11==k) ans++;
		}
	}
	printf("%d\n",ans);

	return 0;
}
