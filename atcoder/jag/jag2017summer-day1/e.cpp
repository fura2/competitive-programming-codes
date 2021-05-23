#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class mint{
	static const int MOD=998244353;
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

mint operator+(long long x,const mint& m){ return m+x; }
mint operator-(long long x,const mint& m){ return -m+x; }
mint operator*(long long x,const mint& m){ return m*x; }

enum{NUMBER,VECTOR,SYMBOL};
struct token{
	int type;
	mint num;
	pair<mint,mint> vec;
	char sym;
};

vector<token> T;
void tokenize(string s){
	int n=s.length();
	int idx=0;
	while(idx<n){
		if(isdigit(s[idx])){
			mint num=0;
			while(idx<n && isdigit(s[idx])){
				num=10*num+(s[idx++]-'0');
			}
			token t;
			t.type=NUMBER;
			t.num=num;
			T.emplace_back(t);
		}
		else{
			token t;
			t.type=SYMBOL;
			t.sym=s[idx++];
			T.emplace_back(t);
		}
	}
}

int idx;
token expr(){
	if(T[idx].type==NUMBER) return T[idx++];

	assert(T[idx].type==SYMBOL && T[idx].sym=='(');

	idx++;
	token t1=expr();

	assert(idx<T.size() && T[idx].type==SYMBOL && (T[idx].sym==',' || T[idx].sym=='*'));
	char op=T[idx].sym;
	idx++;
	token t2=expr();
	assert(idx<T.size() && T[idx].type==SYMBOL && T[idx].sym==')');
	idx++;

	token t3;
	if(op==','){
		assert(t1.type==NUMBER && t2.type==NUMBER);
		t3.type=VECTOR;
		t3.vec={t1.num,t2.num};
	}
	else{ // op=='*'
		if(t1.type==NUMBER && t2.type==NUMBER){
			t3.type=NUMBER;
			t3.num=t1.num*t2.num;
		}
		else if(t1.type==NUMBER && t2.type==VECTOR){
			t3.type=VECTOR;
			t3.vec.first=t1.num*t2.vec.first;
			t3.vec.second=t1.num*t2.vec.second;
		}
		else if(t1.type==VECTOR && t2.type==NUMBER){
			t3.type=VECTOR;
			t3.vec.first=t2.num*t1.vec.first;
			t3.vec.second=t2.num*t1.vec.second;
		}
		else{ // VECTOR, VECTOR
			t3.type=NUMBER;
			t3.num=t1.vec.first*t2.vec.first+t1.vec.second*t2.vec.second;
		}
	}
	return t3;
}

int main(){
	string s; cin>>s;
	tokenize(s);
	cout<<expr().num<<'\n';
	return 0;
}
