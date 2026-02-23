#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint p; scanf("%d%lld",&n,&p);
	vector<int> w(n),b(n);
	rep(i,n) scanf("%d%d",&w[i],&b[i]);

	vector<lint> a(n);
	lint r=0;
	rep(i,n){
		a[i]=(100-p)*w[i]+p*b[i];
		r+=p*b[i];
	}
	sort(a.rbegin(),a.rend());

	lint sum=0;
	rep(i,n){
		sum+=a[i];
		if(sum>=r){
			printf("%d\n",i+1);
			break;
		}
	}

	return 0;
}
