#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,p;
	lint k; scanf("%d%lld%d",&n,&k,&p);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d",&a[i]);
	rep(j,n) scanf("%d",&b[j]);

	sort(b.begin(),b.end());

	auto f=[&](int tar){
		lint cnt=0;
		rep(i,n){
			cnt+=upper_bound(b.begin(),b.end(),tar-a[i])-b.begin();
			cnt+=upper_bound(b.begin(),b.end(),tar+p-a[i])-lower_bound(b.begin(),b.end(),p-a[i]);
		}
		return cnt;
	};

	int lo=-1,hi=p;
	while(hi-lo>1){
		int mi=(lo+hi)/2;
		if(f(mi)>=k) hi=mi;
		else         lo=mi;
	}
	printf("%d\n",hi);

	return 0;
}
