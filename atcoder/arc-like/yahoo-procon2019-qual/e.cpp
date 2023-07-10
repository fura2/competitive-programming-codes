#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class F2{
	bool x;
public:
	F2():x(false){}
	F2(long long n){ assert(n==0||n==1); x=(n==1); }
	F2& operator+=(const F2& a){ x=(x!=a.x); return *this; }
	F2& operator-=(const F2& a){ return (*this)+=a; }
	F2& operator*=(const F2& a){ x=(x&&a.x); return *this; }
	F2& operator/=(const F2& a){ assert(a.x); return *this; }
	F2 operator+(const F2& a)const{ return F2(*this)+=a; }
	F2 operator-(const F2& a)const{ return F2(*this)-=a; }
	F2 operator*(const F2& a)const{ return F2(*this)*=a; }
	F2 operator/(const F2& a)const{ return F2(*this)/=a; }
	bool operator==(const F2& a)const{ return x==a.x; }
	bool operator!=(const F2& a)const{ return !((*this)==a); }
	int to_int()const{ return x; }
};

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

int matrix_rank(matrix<F2> A){
	int m=A.h(),n=A.w(),r=0;
	rep(j,n){
		int piv;
		for(piv=r;piv<m;piv++) if(A[piv][j]==1) break;
		if(piv==m) continue;
		if(piv!=r){
			rep(k,n) swap(A[piv][k],A[r][k]);
		}
		for(int i=r+1;i<m;i++) if(A[i][j]==1) {
			for(int k=j;k<n;k++) A[i][k]-=A[r][k];
		}
		r++;
	}
	return r;
}

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

mint operator+(long long y,const mint& m){ return m+y; }
mint operator*(long long y,const mint& m){ return m*y; }

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

int main(){
	int m,n; scanf("%d%d",&m,&n);
	matrix<F2> A(m,n);
	rep(i,m) rep(j,n) { int a; scanf("%d",&a); A[i][j]=a; }

	cout<<pow(mint(2),m+n-1)-pow(mint(2),m+n-matrix_rank(A)-1)<<'\n';

	return 0;
}
