#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class mint{
	static const int MOD=1e9+7;
	int x;
public:
	mint():x(0){}
	mint(long long y){ x=y%MOD; if(x<0) x+=MOD; }

	mint& operator+=(const mint& m){ x+=m.x; if(x>=MOD) x-=MOD; return *this; }
	mint& operator-=(const mint& m){ x-=m.x; if(x<   0) x+=MOD; return *this; }
	mint& operator*=(const mint& m){ x=1LL*x*m.x%MOD; return *this; }
	mint operator+(const mint& m)const{ return mint(*this)+=m; }
	mint operator-(const mint& m)const{ return mint(*this)-=m; }
	mint operator*(const mint& m)const{ return mint(*this)*=m; }

	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
};

struct state{
	mint r,s,p;
	state operator+(const state& x)const{ return {r*x.r+r*x.s+s*x.r,s*x.s+s*x.p+p*x.s,p*x.p+p*x.r+r*x.p}; }
	state operator-(const state& x)const{ return {r*x.r+r*x.p+p*x.r,s*x.s+s*x.r+r*x.s,p*x.p+p*x.s+s*x.p}; }
	state operator*(const state& x)const{ return {r*x.r+s*x.p+p*x.s,s*x.s+r*x.p+p*x.r,p*x.p+r*x.s+s*x.r}; }
};

int n,idx;
string s;

state expression();

state factor(){
	assert(idx<n);

	char c=s[idx++];
	assert(c=='R' || c=='S' || c=='P' || c=='?' || c=='(');
	if(c=='R'){
		return {1,0,0};
	}
	else if(c=='S'){
		return {0,1,0};
	}
	else if(c=='P'){
		return {0,0,1};
	}
	else if(c=='?'){
		return {1,1,1};
	}
	else{
		auto x=expression();
		assert(idx<n && s[idx]==')');
		idx++;
		return x;
	}
}

state term(){
	assert(idx<n);

	auto x=factor();
	while(idx<n && s[idx]=='*'){
		idx++;
		x=x*factor();
	}
	return x;
}

state expression(){
	assert(idx<n);

	auto x=term();
	while(idx<n && (s[idx]=='+' || s[idx]=='-')){
		char op=s[idx++];
		auto y=term();
		x=(op=='+'?x+y:x-y);
	}
	return x;
}

int main(){
	char c; cin>>n>>s>>c;

	auto ans=expression();
	cout<<(c=='R'?ans.r:c=='S'?ans.s:ans.p)<<'\n';

	return 0;
}
