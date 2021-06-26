#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; scanf("%lld",&n);

	int cnt=0;
	for(lint p=2;p*p<=n;p++){
		while(n%p==0){
			n/=p;
			cnt++;
		}
	}
	if(n>1) cnt++;

	int ans;
	for(ans=0;(1<<ans)<cnt;ans++);
	printf("%d\n",ans);

	return 0;
}
