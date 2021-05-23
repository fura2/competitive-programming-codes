#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

inline int popcount(int x){
	x=((x>>1)&0x55555555)+(x&0x55555555);
	x=((x>>2)&0x33333333)+(x&0x33333333);
	x=((x>>4)+x)&0x0f0f0f0f;
	x+=(x>>8);
	x+=(x>>16);
	return x&0x3f;
}

int main(){
	int n,k,s,t; scanf("%d%d%d%d",&n,&k,&s,&t);

	if((s&t)!=s) return puts("0"),0;

	lint choose[51][51]={1};
	rep(i,n){
		choose[i+1][0]=1;
		rep(j,i+1) choose[i+1][j+1]=choose[i][j]+choose[i][j+1];
	}

	lint coef[51]={};
	rep(i,n+1) for(int j=1;j<=k;j++) coef[i]+=choose[i][j];

	vector<int> a;
	rep(i,n){
		int x; scanf("%d",&x);
		bool ok=true;
		rep(i,18){
			if((s>>i&1)==0 && (t>>i&1)==0){
				if((x>>i&1)!=0) ok=false;
			}
			if((s>>i&1)==1 && (t>>i&1)==1){
				if((x>>i&1)!=1) ok=false;
			}
		}
		if(ok) a.emplace_back(x);
	}
	n=a.size();

	vector<int> D;
	rep(i,18) if((s>>i&1)!=(t>>i&1)) D.emplace_back(i);
	int m=D.size();
	{
		vector<int> b(n);
		rep(i,n){
			rep(j,m) if(a[i]>>D[j]&1) b[i]|=1<<j;
		}
		a=b;
	}

	lint ans=0;
	rep(S,1<<m){
		lint tmp=0;
		map<int,int> f;
		rep(i,n) ++f[a[i]&S];
		for(auto p:f) tmp+=coef[p.second];
		if(popcount(S)%2==0) ans+=tmp;
		else                 ans-=tmp;
	}
	printf("%lld\n",ans);

	return 0;
}
