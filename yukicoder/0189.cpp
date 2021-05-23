#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class mint{
	static const int MOD=1e9+9;
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

string s;

vector<mint> dfs(int i,bool smaller){
	vector<mint> res(1801);
	if(i==s.length()){
		res[0]=1;
		return res;
	}

	if(smaller){
		auto tmp=dfs(i+1,true);
		rep(d,10) rep(x,1801-d) res[x+d]+=tmp[x];
	}
	else{
		auto tmp1=dfs(i+1,false);
		auto tmp2=dfs(i+1,true);
		rep(d,10) rep(x,1801-d) {
			if     (d==s[i]-'0') res[x+d]+=tmp1[x];
			else if(d< s[i]-'0') res[x+d]+=tmp2[x];
		}
	}
	return res;
}

int main(){
	string s1,s2; cin>>s1>>s2;

	s=s1;
	auto a1=dfs(0,false);
	s=s2;
	auto a2=dfs(0,false);

	mint ans=0;
	for(int x=1;x<=1800;x++) ans+=a1[x]*a2[x];
	cout<<ans<<'\n';

	return 0;
}
