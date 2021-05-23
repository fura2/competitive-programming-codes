#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<int MOD>
class mint{
	int x;
public:
	mint():x(0){}
	mint(long long y){ x=y%MOD; if(x<0) x+=MOD; }

	mint &operator+=(const mint &m){ x+=m.x; if(x>=MOD) x-=MOD; return *this; }
	mint &operator-=(const mint &m){ x-=m.x; if(x<   0) x+=MOD; return *this; }
	mint &operator*=(const mint &m){ x=1LL*x*m.x%MOD; return *this; }
	mint operator+(const mint &m)const{ return mint(*this)+=m; }
	mint operator-(const mint &m)const{ return mint(*this)-=m; }
	mint operator*(const mint &m)const{ return mint(*this)*=m; }

	friend ostream &operator<<(ostream &os,const mint &m){ return os<<m.x; }
};

template<class R>
class matrix{
	vector<vector<R>> a;
public:
	matrix(int n):a(n,vector<R>(n)){}
	matrix(int m,int n):a(m,vector<R>(n)){}

	const vector<R> &operator[](int i)const{ return a[i]; }
	vector<R> &operator[](int i){ return a[i]; }
	matrix &operator+=(const matrix &A){
		int m=size1(),n=size2();
		rep(i,m) rep(j,n) (*this)[i][j]+=A[i][j];
		return *this;
	}
	matrix &operator-=(const matrix &A){
		int m=size1(),n=size2();
		rep(i,m) rep(j,n) (*this)[i][j]-=A[i][j];
		return *this;
	}
	matrix &operator*=(const matrix &A){
		int m=size1(),n=size2(),l=A.size2();
		matrix B(m,l);
		rep(i,m) rep(j,l) rep(k,n) B[i][j]+=(*this)[i][k]*A[k][j];
		swap(*this,B);
		return *this;
	}
	matrix operator+(const matrix &A)const{ return matrix(*this)+=A; }
	matrix operator-(const matrix &A)const{ return matrix(*this)-=A; }
	matrix operator*(const matrix &A)const{ return matrix(*this)*=A; }

	int size1()const{ return a.size(); }
	int size2()const{ return a[0].size(); }

	static matrix identity(int n){
		matrix I(n);
		rep(i,n) I[i][i]=R(1);
		return I;
	}
};

template<class R>
matrix<R> pow(matrix<R> A,long long k){
	matrix<R> B=matrix<R>::identity(A.size1());
	for(;k>0;k>>=1){
		if(k&1) B*=A;
		A*=A;
	}
	return B;
}

int main(){
	using mint=mint<1000000007>;

	int h,r,g[16][16]; cin>>h>>r;
	rep(i,r) rep(j,r) cin>>g[i][j];

	matrix<mint> A(r);
	rep(i,r){
		mint dp[1<<16][16];
		dp[1<<i][i]=1;
		rep(S,1<<r) if(S&(1<<i)) rep(j,r) if(S&(1<<j)) {
			rep(k,r) if(!(S&(1<<k)) && g[j][k]) {
				dp[S|(1<<k)][k]+=dp[S][j];
			}
		}
		rep(S,1<<r) rep(j,r) A[i][j]+=dp[S][j];
	}

	cout<<pow(A,h)[0][0]<<endl;

	return 0;
}
