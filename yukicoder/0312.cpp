#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; scanf("%lld",&n);
	for(lint i=3;i*i<=n;i++){
		if(n%i==0){
			printf("%lld\n",i);
			return 0;
		}
	}
	printf("%lld\n",n!=4&&n%2==0?n/2:n);
	return 0;
}
