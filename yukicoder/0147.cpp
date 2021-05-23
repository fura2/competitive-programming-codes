#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class R>
class matrix{
	vector<vector<R>> a;
public:
	matrix(int n):a(n,vector<R>(n)){}
	matrix(int m,int n):a(m,vector<R>(n)){}

	matrix& operator+=(const matrix& A){
		assert(h()==A.h() && w()==A.w());
		int m=h(),n=w();
		rep(i,m) rep(j,n) (*this)[i][j]+=A[i][j];
		return *this;
	}
	matrix& operator-=(const matrix& A){
		assert(h()==A.h() && w()==A.w());
		int m=h(),n=w();
		rep(i,m) rep(j,n) (*this)[i][j]-=A[i][j];
		return *this;
	}
	matrix& operator*=(const matrix& A){
		assert(w()==A.h());
		int m=h(),n=w(),l=A.w();
		matrix B(m,l);
		rep(i,m) rep(j,l) rep(k,n) B[i][j]+=(*this)[i][k]*A[k][j];
		swap(*this,B);
		return *this;
	}
	matrix operator+(const matrix& A)const{ return matrix(*this)+=A; }
	matrix operator-(const matrix& A)const{ return matrix(*this)-=A; }
	matrix operator*(const matrix& A)const{ return matrix(*this)*=A; }
	const vector<R>& operator[](int i)const{ return a[i]; }
	vector<R>& operator[](int i){ return a[i]; }

	vector<R> operator*(const vector<R>& v)const{
		assert(w()==v.size());
		int m=h(),n=w();
		vector<R> res(m);
		rep(i,m) rep(j,n) res[i]+=(*this)[i][j]*v[j];
		return res;
	}

	int h()const{ return a.size(); }
	int w()const{ return a.empty()?0:a[0].size(); }

	static matrix identity(int n){
		matrix I(n);
		rep(i,n) I[i][i]=R{1};
		return I;
	}
};

template<class R>
matrix<R> pow(matrix<R> A,long long k){
	assert(A.h()==A.w());
	matrix<R> B=matrix<R>::identity(A.h());
	for(;k>0;k>>=1){
		if(k&1) B*=A;
		A*=A;
	}
	return B;
}

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
	bint(const string& s){ *this=s; }
	bint& operator=(long long v){
		if(v>=0) sign=1;
		else sign=-1, v*=-1;
		a.clear();
		for(;v>0;v/=BASE) a.emplace_back(v%BASE);
		return *this;
	}
	bint& operator=(const string& s){
		int n=s.length(),t=0;
		sign=1;
		if     (s[0]=='+') t++;
		else if(s[0]=='-') t++, sign=-1;
		a.clear();
		for(int i=n;i>t;i-=9) a.emplace_back(stoi(s.substr(max(i-9,t),i-max(i-9,t))));
		return normalize();
	}
	bint& operator+=(const bint& b){
		int m=a.size(),n=b.a.size(),carry=0;
		if(sign==b.sign){
			if(m<n) a.resize(n), m=n;
			rep(i,n){
				a[i]+=b.a[i]+carry;
				if(a[i]>=BASE) a[i]-=BASE, carry=1;
				else carry=0;
			}
			for(int i=n;carry>0;i++){
				if(a.size()==i) a.resize(i+1);
				a[i]+=carry;
				if(a[i]>=BASE) a[i]-=BASE, carry=1;
				else carry=0;
			}
		}
		else if(abs(*this)>=abs(b)){
			rep(i,n){
				a[i]-=b.a[i]+carry;
				if(a[i]<0) a[i]+=BASE, carry=1;
				else carry=0;
			}
			for(int i=n;carry>0;i++){
				a[i]-=carry;
				if(a[i]<0) a[i]+=BASE, carry=1;
				else carry=0;
			}
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
	bint& operator*=(const long long& v){ return *this=(*this)*bint(v); }
	bint& operator/=(const long long& v){ return *this=(*this)/bint(v); }
	bint& operator*=(const bint& b){ return *this=(*this)*b; }
	bint& operator/=(const bint& b){ return *this=(*this)/b; }
	bint& operator%=(const bint& b){ return *this=(*this)%b; }
	bint operator+(const bint& b)const{ return bint(*this)+=b; }
	bint operator-(const bint& b)const{ return bint(*this)-=b; }
	bint operator*(int v)const{ return bint(*this)*=v; }
	bint operator/(int v)const{ return bint(*this)/=v; }
	bint operator*(const long long& v)const{ return bint(*this)*=bint(v); }
	bint operator/(const long long& v)const{ return bint(*this)/=bint(v); }
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
	friend istream& operator>>(istream& is,bint& b){
		string s;
		is>>s;
		b=bint(s);
		return is;
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

string to_string(const bint& b){
	stringstream ss;
	ss<<b;
	return ss.str();
}

class mint{
	static const int MOD=1e9+7;
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

int main(){
	matrix<mint> A(2);
	A[0][1]=A[1][0]=A[1][1]=1;

	int n; cin>>n;
	mint ans=1;
	rep(i,n){
		lint m;
		bint t; cin>>m>>t;
		mint a=pow(A,m+2)[0][1];
		if(a.to_int()==0) ans=0;
		else ans*=pow(a,stoi(to_string(t%1000000006)));
	}
	cout<<ans<<'\n';

	return 0;
}
