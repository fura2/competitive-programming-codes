#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint f(lint base){
	lint res=0,x=base,pw=1;
	while(1){
		res+=(x%10)*pw;
		x/=10;
		if(x==0) break;
		pw*=base;
	}
	return res;
}

int main(){
	lint a; scanf("%lld",&a);

	lint lo=10,hi=1e4+1;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;
		if(f(mi)<=a) lo=mi; else hi=mi;
	}
	printf("%lld\n",f(lo)==a?lo:-1);

	return 0;
}
