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

bool is_solvable(matrix<F2> A,vector<F2> b){
	int h=A.h(),w=A.w();
	assert(h==b.size());
	matrix<F2> A2(h,w+1);
	rep(i,h){
		rep(j,w) A2[i][j]=A[i][j];
		A2[i][w]=b[i];
	}
	return matrix_rank(A)==matrix_rank(A2);
}

int main(){
	int n; scanf("%d",&n);
	vector<int> d(n),w(n);
	rep(i,n) scanf("%d",&d[i]);
	rep(i,n) scanf("%d",&w[i]);

	matrix<F2> A(n);
	rep(i,n){
		A[(i-d[i]%n+n)%n][i]=1;
		A[(i+d[i])%n][i]=1;
	}
	vector<F2> b(n);
	rep(i,n) b[i]=1-w[i];

	puts(is_solvable(A,b)?"Yes":"No");

	return 0;
}
