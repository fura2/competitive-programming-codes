#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class bint{
	static const int BASE=1000000000;
	int sign;
	vector<int> a;

	bint& normalize(){
		while(!a.empty() && a.back()==0) a.pop_back();
		if(a.empty()) sign=1;
		return *this;
	}
public:
	bint(long long v=0){ *this=v; }

	bint& operator+=(const bint& b){
		int m=a.size(),n=b.a.size(),carry=0;
		if(sign==b.sign){
			if(m<n) a.resize(n), m=n;
			rep(i,n){
				a[i]+=b.a[i]+carry;
				if(a[i]>=BASE) a[i]-=BASE, carry=1;
				else carry=0;
			}
			if(carry>0){
				if(a.size()==n) a.resize(n+1);
				a[n]+=carry;
			}
		}
		else if(abs(*this)>=abs(b)){
			rep(i,n){
				a[i]-=b.a[i]+carry;
				if(a[i]<0) a[i]+=BASE, carry=1;
				else carry=0;
			}
			if(carry>0) a[n]-=carry;
		}
		else{
			a.resize(n);
			rep(i,n){
				a[i]=b.a[i]-(a[i]+carry);
				if(a[i]<0) a[i]+=BASE, carry=1;
				else carry=0;
			}
			sign*=-1;
		}
		return normalize();
	}
	bint& operator-=(const bint& b){
		sign*=-1;
		*this+=b;
		sign*=-1;
		return normalize();
	}
	bint& operator*=(int v){
		if(v<0) sign*=-1, v=-v;
		int n=a.size(),carry=0;
		rep(i,n){
			auto tmp=(long long)a[i]*v+carry;
			a[i]=tmp%BASE;
			carry=tmp/BASE;
		}
		if(carry>0) a.emplace_back(carry);
		return normalize();
	}
	bint& operator/=(int v){
		if(v<0) sign*=-1, v*=-1;
		for(int i=a.size()-1,rem=0;i>=0;i--){
			auto tmp=a[i]+(long long)rem*BASE;
			a[i]=tmp/v;
			rem=tmp%v;
		}
		return normalize();
	}
	bint& operator*=(const bint& b){ return *this=(*this)*b; }
	bint& operator/=(const bint& b){ return *this=(*this)/b; }
	bint operator+(const bint& b)const{ return bint(*this)+=b; }
	bint operator-(const bint& b)const{ return bint(*this)-=b; }
	bint operator*(int v)const{ return bint(*this)*=v; }
	bint operator/(int v)const{ return bint(*this)/=v; }
	bint operator*(const bint& b)const{
		int m=a.size(),n=b.a.size();
		if(m==0 || n==0) return 0;
		bint res;
		res.a.resize(m+n);
		rep(i,m) rep(j,n) {
			auto tmp=(long long)a[i]*b.a[j];
			res.a[i+j]+=tmp%BASE;
			if(tmp>=BASE) res.a[i+j+1]+=tmp/BASE;
			for(int k=0;;k++){
				if(k>0 && res.a[i+j+k]<BASE) break;
				if(res.a[i+j+k]>=BASE){
					res.a[i+j+k]-=BASE;
					res.a[i+j+k+1]++;
				}
			}
		}
		res.sign=sign*b.sign;
		return res.normalize();
	}
	bint operator/(const bint& b)const{ return divmod(*this,b).first; }
	bint operator%(const bint& b)const{ return divmod(*this,b).second; }
	bint operator-()const{ bint res=*this; if(res!=0) res.sign*=-1; return res; }
	bool operator< (const bint& b)const{
		if(sign!=b.sign) return sign<b.sign;
		int m=a.size(),n=b.a.size();
		if(m!=n) return sign==1?m<n:m>n;
		for(int i=m-1;i>=0;i--) if(a[i]!=b.a[i]) return sign==1?a[i]<b.a[i]:a[i]>b.a[i];
		return false;
	}
	bool operator> (const bint& b)const{ return b<(*this); }
	bool operator<=(const bint& b)const{ return !(b<(*this)); }
	bool operator>=(const bint& b)const{ return !((*this)<b); }
	bool operator==(const bint& b)const{ return !((*this)<b) && !(b<(*this)); }
	bool operator!=(const bint& b)const{ return (*this)<b || b<(*this); }
	bint& operator=(long long v){
		if(v>=0) sign=1;
		else sign=-1, v*=-1;
		a.clear();
		for(;v>0;v/=BASE) a.emplace_back(v%BASE);
		return *this;
	}
	friend ostream& operator<<(ostream& os,const bint& b){
		if(b.sign==-1) os<<'-';
		os<<(b.a.empty()?0:b.a.back());
		for(int i=b.a.size()-2;i>=0;i--) os<<setw(9)<<setfill('0')<<b.a[i];
		return os;
	}

	friend bint abs(const bint& b){ return b.sign==1?b:-b; }

	friend pair<bint,bint> divmod(const bint& a1,const bint& b1){
		int norm=BASE/(b1.a.back()+1);
		bint a=abs(a1)*norm,b=abs(b1)*norm,q,r;
		q.a.resize(a.a.size());
		for(int i=a.a.size()-1;i>=0;i--){
			r*=BASE;
			r+=a.a[i];
			int s1=(r.a.size()<=b.a.size()?0:r.a[b.a.size()]);
			int s2=(r.a.size()<=b.a.size()-1?0:r.a[b.a.size()-1]);
			int d=((long long)BASE*s1+s2)/b.a.back();
			r-=b*d;
			while(r<0) r+=b, d--;
			q.a[i]=d;
		}
		q.sign=a1.sign*b1.sign;
		r.sign=a1.sign;
		return make_pair(q.normalize(),r.normalize()/norm);
	}
};

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

template<class T> T gcd(const T& a,const T& b){ return b==0?a:gcd(b,a%b); }
template<class T> T lcm(const T& a,const T& b){ return a/gcd(a,b)*b; }

int main(){
	int n; cin>>n;

	bint L=1;
	rep(i,n) L=lcm(L,bint{i+1});

	rational<bint> tar{1,L};

	vector<pair<int,int>> ans;
	for(int d=n;d>0;d--){
		for(int i=1;i<d;i++){
			rational<bint> a{i,d};
			if((tar+a).deno()<tar.deno()){
				if(gcd(i,d)==1){
					if(i<=d-i){
						tar+=a;
						ans.emplace_back(-i,d);
					}
					else{
						tar-={d-i,d};
						ans.emplace_back(d-i,d);
					}
				}
				break;
			}
		}
	}
	while(tar!=bint{0}){
		if(tar>bint{0}) ans.emplace_back( 1,1), tar-=1;
		else            ans.emplace_back(-1,1), tar+=1;
	}

	int sum=0;
	for(auto x:ans) sum+=abs(x.first);
	cout<<sum<<'\n';
	for(auto x:ans) if(x.first>0) rep(_,abs(x.first)) cout<<"+ "<<x.second<<'\n';
	for(auto x:ans) if(x.first<0) rep(_,abs(x.first)) cout<<"- "<<x.second<<'\n';

	return 0;
}
