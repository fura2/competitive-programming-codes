#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);

	int zero[30]={},one[30]={};
	rep(i,n){
		int a; scanf("%d",&a);
		rep(b,30){
			if(a>>b&1) one[b]++;
			else       zero[b]++;
		}

		lint ans=0;
		rep(b,30){
			if(one[b]%2==0){
				ans+=(1LL<<b)*one[b];
			}
			else{
				ans+=(1LL<<b)*zero[b];
			}
		}
		printf("%lld\n",ans);
	}

	return 0;
}
