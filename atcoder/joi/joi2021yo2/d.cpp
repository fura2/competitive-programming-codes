#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint k; scanf("%d%lld",&n,&k);
	vector<lint> a(n),b(n);
	rep(i,n) scanf("%lld",&a[i]);
	rep(i,n) scanf("%lld",&b[i]);

	lint lo=a[n-1],hi=1e15;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;
		auto b_tmp=b;

		lint sum=0,tmp=0;
		for(int i=n-1;i>=0;i--){
			// 奥の建物からの繰り越し
			lint mn=min(b[i],tmp);
			b[i]-=mn;
			tmp-=mn;

			lint t=mi-a[i];
			lint j=(b[i]+t-1)/t; // 建物 i に j 人送りこむ
			sum+=j;
			tmp+=t*j-b[i];
		}
		if(sum<=k) hi=mi;
		else       lo=mi;

		b=b_tmp;
	}
	printf("%lld\n",hi);

	return 0;
}
