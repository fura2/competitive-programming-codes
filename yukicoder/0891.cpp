#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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

int main(){
	int a,b,n; cin>>a>>b>>n;

	matrix<mint> A(2);
	A[0][0]=0; A[0][1]=1;
	A[1][0]=b; A[1][1]=a;
	cout<<pow(A,n)[0][1]<<'\n';

	return 0;
}
