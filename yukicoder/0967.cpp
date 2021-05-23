#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

void solve(){
	lint a,b,c,x,y,z; cin>>a>>b>>c>>x>>y>>z;

	lint ans=LLONG_MAX;
	// b が最大
	if(b>=3 && !(a==1 && c==1)){
		lint ta=a,tc=c;

		lint res=0;
		if(a>=b) res+=x*(a-b+1), a=b-1;
		if(c>=b) res+=z*(c-b+1), c=b-1;
		if(a==c) res+=min(x,z);
		ans=min(ans,res);

		a=ta; c=tc;
	}
	// b が最小
	if(a>=2 && c>=2 && !(a==2 && c==2)){
		lint res=0;
		if(a==c){
			res+=min(x,z);
			a--;
		}
		if(b>=min(a,c)) res+=y*(b-min(a,c)+1);
		ans=min(ans,res);
	}
	printf("%lld\n",ans<LLONG_MAX?ans:-1);
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
