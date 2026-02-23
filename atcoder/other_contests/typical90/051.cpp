#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

inline int popcount(unsigned int x){
	x-=(x>>1)&0x55555555;
	x=(x&0x33333333)+((x>>2)&0x33333333);
	return ((x+(x>>4)&0x0f0f0f0f)*0x01010101)>>24;
}

int main(){
	int n,k;
	lint p; cin>>n>>k>>p;
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	vector<lint> L1[21],L2[21];
	rep(S,1<<n/2){
		lint sum=0;
		rep(i,n/2) if(S>>i&1) sum+=a[i];
		L1[popcount(S)].emplace_back(sum);
	}
	rep(S,1<<(n+1)/2){
		lint sum=0;
		rep(i,(n+1)/2) if(S>>i&1) sum+=a[n/2+i];
		L2[popcount(S)].emplace_back(sum);
	}

	rep(i,21){
		sort(L1[i].begin(),L1[i].end());
		sort(L2[i].begin(),L2[i].end());
	}

	lint ans=0;
	rep(i,21){
		int j=k-i;
		if(0<=j && j<=20){
			for(lint x:L1[i]){
				ans+=upper_bound(L2[j].begin(),L2[j].end(),p-x)-L2[j].begin();
			}
		}
	}
	printf("%lld\n",ans);

	return 0;
}
