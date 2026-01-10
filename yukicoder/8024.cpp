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

template<class T> T gcd(const T& a,const T& b){ return b==0?a:gcd(b,a%b); }

template<class T>
class rational{
	T num,den;

	rational& reduce(){
		T g=gcd(num,den);
		if(g<-1) g*=-1;
		if(g>1) num/=g, den/=g;
		return *this;
	}
public:
	rational(const T& num=0){ *this=num; }
	rational(const T& num,const T& den):num(num),den(den){
		if(den<0){
			this->num*=-1;
			this->den*=-1;
		}
		reduce();
	}
	const T& nume()const{ return num; }
	const T& deno()const{ return den; }
	rational& operator+=(const T& v){ num+=den*v; return reduce(); }
	rational& operator-=(const T& v){ num-=den*v; return reduce(); }
	rational& operator+=(const rational& r){
		T g=gcd(den,r.den);
		den/=g;
		num*=r.den/g;
		num+=den*r.num;
		den*=r.den;
		return reduce();
	}
	rational& operator-=(const rational& r){
		T g=gcd(den,r.den);
		den/=g;
		num*=r.den/g;
		num-=den*r.num;
		den*=r.den;
		return reduce();
	}
	rational& operator*=(const rational& r){
		T g1=gcd(num,r.den),g2=gcd(den,r.num);
		num/=g1; num*=r.num/g2;
		den/=g2; den*=r.den/g1;
		if(den<0) num*=-1, den*=-1;
		return reduce();
	}
	rational& operator/=(const rational& r){
		T g1=gcd(num,r.num),g2=gcd(den,r.den);
		num/=g1; num*=r.den/g2;
		den/=g2; den*=r.num/g1;
		if(den<0) num*=-1, den*=-1;
		return reduce();
	}
	rational operator+(const T& v)const{ return rational(*this)+=v; }
	rational operator-(const T& v)const{ return rational(*this)-=v; }
	rational operator+(const rational& r)const{ return rational(*this)+=r; }
	rational operator-(const rational& r)const{ return rational(*this)-=r; }
	rational operator*(const rational& r)const{ return rational(*this)*=r; }
	rational operator/(const rational& r)const{ return rational(*this)/=r; }
	bool operator< (const rational& r)const{ return num*r.den<r.num*den; }
	bool operator> (const rational& r)const{ return r<(*this); }
	bool operator<=(const rational& r)const{ return !(r<(*this)); }
	bool operator>=(const rational& r)const{ return !((*this)<r); }
	bool operator==(const rational& r)const{ return !((*this)<r) && !(r<(*this)); }
	bool operator!=(const rational& r)const{ return (*this)<r || r<(*this); }
	rational& operator=(const T& v){ num=v; den=1; return *this; }
	friend ostream& operator<<(ostream& os,const rational& r){ return os<<r.num<<'/'<<r.den; }

	friend rational abs(const rational& r){ return rational(abs(r.den),r.num); }
};

int n,a[7];

bool vis[1<<7];
set<rational<lint>> memo[1<<7];

inline void add(int S,const rational<lint> x){
	// n = 7 で 5 or 6 個の数を使って作れる数を列挙する際,
	// 使わない 1 or 2 個の整数から作れる数と一致するかどうかを直接判定することで高速化
	if(popcount(S)>=5){
		if(memo[((1<<n)-1)&~S].count(x)>0){
			puts("YES");
			exit(0);
		}
		else return;
	}
	memo[S].emplace(x);
}

void dfs(int S){
	if(vis[S]) return;
	vis[S]=true;

	if(S==0) return;

	rep(i,n) if(S==(1<<i)) {
		add(S,a[i]);
		return;
	}

	rep(T,1<<n) if((T&S)==T && T!=0 && T!=S) {
		dfs(T);
		dfs(S&~T);
		for(auto x:memo[T]) for(auto y:memo[S&~T]) {
			add(S,x+y);
			add(S,x-y);
			add(S,y-x);
			add(S,x*y);
			if(y!=0) add(S,x/y);
			if(x!=0) add(S,y/x);
		}
	}
}

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);

	rep(k,n) rep(S,1<<n) if(popcount(S)==k) dfs(S);

	rep(S,1<<n) rep(T,1<<n) if(S!=0 && T!=0 && (S&T)==0) {
		for(auto x:memo[S]) if(memo[T].count(x)>0) return puts("YES"),0;
	}
	puts("NO");

	return 0;
}
