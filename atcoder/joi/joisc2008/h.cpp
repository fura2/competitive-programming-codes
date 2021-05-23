// Day 3: Fraction

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

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

int main(){
	lint m,k; cin>>m>>k;

	priority_queue<rational<lint>,vector<rational<lint>>,greater<>> Q;
	for(lint d=2;d<=m;d++){
		Q.emplace(1,d);
	}
	while(!Q.empty()){
		auto r=Q.top(); Q.pop();
		lint n=r.nume(),d=r.deno();
		k--;
		if(k==0){
			cout<<n<<' '<<d<<'\n';
			return 0;
		}
		for(n++;n<d;n++) if(gcd(n,d)==1) {
			Q.emplace(n,d);
			break;
		}
	}
	cout<<"-1\n";

	return 0;
}
