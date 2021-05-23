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
		rep(i,n) I[i][i]=R::ONE;
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

class max_plus_algebra{
	lint x;
public:
	const static lint ZERO=LLONG_MIN;
	const static lint ONE=0;

	max_plus_algebra():x(ZERO){}
	max_plus_algebra(lint x):x(x){}
	max_plus_algebra& operator+=(const max_plus_algebra& a){ x=max(x,a.x); return *this; }
	max_plus_algebra& operator*=(const max_plus_algebra& a){ x+=a.x; return *this; }
	max_plus_algebra operator+(const max_plus_algebra& a)const{ return max_plus_algebra(*this)+=a; }
	max_plus_algebra operator*(const max_plus_algebra& a)const{ return max_plus_algebra(*this)*=a; }
	lint to_int()const{ return x; }
};

int main(){
	lint k;
	int n; scanf("%lld%d",&k,&n);
	matrix<max_plus_algebra> A(n);
	rep(i,n) rep(j,n) {
		int a; scanf("%d",&a);
		A[i][j]=a;
	}

	vector<max_plus_algebra> x(n,0);
	x=pow(A,k-1)*x;

	lint ans=LLONG_MIN;
	rep(i,n) ans=max(ans,x[i].to_int());
	printf("%lld\n",ans);

	return 0;
}
