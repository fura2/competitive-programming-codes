#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k;
	string s; cin>>n>>k>>s;

	vector<int> sum(n+1);
	rep(i,n) sum[i+1]=sum[i]+(s[i]-'0');

	lint lo=0,hi=k;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;

		lint cnt=0,x=mi;
		for(int t=0;x>0;t++){
			if(cnt>=k || t>3000){
				cnt=k;
				break;
			}
			lint c1=sum[n]*(cnt/n)+sum[cnt%n];
			cnt+=x;
			lint c2=sum[n]*(cnt/n)+sum[cnt%n];
			x=c2-c1;
		}
		if(cnt>=k) hi=mi;
		else       lo=mi;
	}
	printf("%lld\n",hi);

	return 0;
}
