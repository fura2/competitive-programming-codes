#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

bool is_kadomatsu(lint a,lint b,lint c){
	if(a<0 || b<0 || c<0 || a==b || a==c || b==c) return false;
	if((a<b && b>c) || (a>b && b<c)) return true;
	return false;
}

int main(){
	lint d,a,b,c; cin>>d>>a>>b>>c;

	if(d==0){
		puts(is_kadomatsu(a,b,c)?"0":"-1");
		return 0;
	}

	lint ans=INF;
	// b が最大値になるケース
	{
		lint ta=a,tb=b,tc=c;

		lint res=0;
		if(a>=b){
			lint k=(a-b)/d+1;
			res+=k;
			a=max(a-k*d,0LL);
		}
		if(c>=b){
			lint k=(c-b)/d+1;
			res+=k;
			c=max(c-k*d,0LL);
		}
		if(a==c) res++, a=max(a-d,0LL);
		if(is_kadomatsu(a,b,c)) ans=min(ans,res);

		a=ta; b=tb; c=tc;
	}
	// b が最小値になるケース
	{
		lint res=0;
		if(a==c) res++, a=max(a-d,0LL);
		if(b>=min(a,c)){
			lint k=(b-min(a,c))/d+1;
			res+=k;
			b=max(b-k*d,0LL);
		}
		if(is_kadomatsu(a,b,c)) ans=min(ans,res);
	}
	printf("%lld\n",ans<INF?ans:-1);

	return 0;
}
