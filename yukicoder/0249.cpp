#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int ans=0;
	bool flag=false;
	rep(i,1000){
		lint n,k; scanf("%lld%lld",&n,&k);
		if(i==0){
			if((n-1)%(k+1)!=0) ans++;
			else flag=true;
		}
		else if(flag){
			ans++;
			flag=false;
		}
		else{
			flag=true;
		}
	}
	printf("%d\n",ans);

	return 0;
}
