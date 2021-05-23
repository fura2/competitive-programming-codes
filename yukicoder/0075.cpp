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

vector<double> Gauss_Jordan(const matrix<double>& A,const vector<double>& b){
	const double EPS=1e-8;

	assert(A.h()==A.w() && A.w()==b.size());

	int n=A.h();
	matrix<double> B(n,n+1);
	rep(i,n){
		rep(j,n) B[i][j]=A[i][j];
		B[i][n]=b[i];
	}

	rep(i,n){
		int pivot=i;
		for(int j=i;j<n;j++) if(abs(B[j][i])>abs(B[pivot][i])) pivot=j;
		rep(j,n+1) swap(B[i][j],B[pivot][j]);
		assert(abs(B[i][i])>EPS);
		for(int j=i+1;j<=n;j++) B[i][j]/=B[i][i];
		rep(j,n) if(i!=j) for(int k=i+1;k<=n;k++) B[j][k]-=B[j][i]*B[i][k];
	}

	vector<double> x(n);
	rep(i,n) x[i]=B[i][n];
	return x;
}

int main(){
	int n; scanf("%d",&n);
	matrix<double> A(n);
	rep(i,n){
		A[i][i]=1;
		for(int d=1;d<=6;d++){
			if(i+d<n) A[i][i+d]-=1.0/6;
			if(i+d>n) A[i][ 0 ]-=1.0/6;
		}
	}

	printf("%.9f\n",Gauss_Jordan(A,vector<double>(n,1))[0]);

	return 0;
}
