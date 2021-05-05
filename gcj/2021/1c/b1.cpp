#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using ulint=unsigned long long;

const long long TEN[19]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000,1000000000000,10000000000000,100000000000000,1000000000000000,10000000000000000,100000000000000000,1000000000000000000};

int length(ulint x){
	return to_string(x).length();
}

// find minimum y s.t.
//   y = x @ (x+1) @ (x+2) @ ... and y != x and y > tar (@ : string concat)
ulint naive(ulint x,ulint tar){
	ulint res=x;
	int len=length(x);
	do{
		x++;
		len+=length(x);
		if(len>=20){
			return ULLONG_MAX;
		}
		res=res*TEN[length(x)]+x;
	}while(res<=tar);
	return res;
}

void solve(){
	ulint tar; cin>>tar;
	int n=length(tar);

	ulint ans=ULLONG_MAX;
	for(int i=1;i<1000;i++){
		ans=min(ans,naive(i,tar));
	}

	for(int i=2;i<=10;i++){
		rep(d,30){
			ans=min(ans,naive(TEN[i]-d,tar));
		}
	}

	for(int d=3;d<n;d++) if(n%d==0) {
		ulint lo=TEN[d-1]-1,hi=TEN[d]-n/d;
		if(length(naive(hi,tar))!=n){
			continue;
		}
		while(hi-lo>1){
			ulint mi=(lo+hi)/2;
			if(length(naive(mi,tar))==n) hi=mi;
			else                         lo=mi;
		}
		ans=min(ans,naive(hi,tar));
	}

	cout<<ans<<'\n';
}

int main(){
	int q; scanf("%d",&q);
	rep(_,q){
		printf("Case #%d: ",_+1);
		solve();
	}
	return 0;
}
