#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int MOD;
class mint{
	int x;
public:
	mint():x(0){}
	mint(long long y){ x=y%MOD; if(x<0) x+=MOD; }

	mint& operator+=(const mint& m){ x+=m.x; if(x>=MOD) x-=MOD; return *this; }
	mint& operator-=(const mint& m){ x-=m.x; if(x<   0) x+=MOD; return *this; }
	mint& operator*=(const mint& m){ x=1LL*x*m.x%MOD; return *this; }
	mint& operator/=(const mint& m){ return *this*=inverse(m); }
	mint operator+(const mint& m)const{ return mint(*this)+=m; }
	mint operator-(const mint& m)const{ return mint(*this)-=m; }
	mint operator*(const mint& m)const{ return mint(*this)*=m; }
	mint operator/(const mint& m)const{ return mint(*this)/=m; }
	mint operator-()const{ return mint(-x); }

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=mint(t); return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

mint operator+(long long x,const mint& m){ return mint(x)+m; }
mint operator-(long long x,const mint& m){ return mint(x)-m; }
mint operator*(long long x,const mint& m){ return mint(x)*m; }
mint operator/(long long x,const mint& m){ return mint(x)/m; }

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

int ask(int t,int l,int b,int r){
	map<tuple<int,int,int,int>,int> memo;
	if(memo.count({t,l,b,r})>0) return memo[{t,l,b,r}];

	printf("? %d %d %d %d\n",t,l,b,r);
	fflush(stdout);
	int res; scanf("%d",&res);
	return memo[{t,l,b,r}]=res;
}

int main(){
	int h,w,n; scanf("%d%d%d%d",&h,&w,&n,&MOD);

	mint ans=0;
	rep(i,h){
		int m=ask(i,0,i,w-1);
		int lo,hi=-1;
		for(int k=1;k<=m;k++){
			lo=hi;
			hi=w-1;
			while(hi-lo>1){
				int mi=(lo+hi)/2;
				if(ask(i,0,i,mi)>=k) hi=mi;
				else                 lo=mi;
			}
			ans+=pow(mint(2),i*w+hi);
		}
	}
	printf("! %d\n",ans.to_int());

	return 0;
}
