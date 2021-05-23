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

int main(){
	int n,x0,y0; scanf("%d%d%d",&n,&x0,&y0);
	vector A(n,matrix<lint>(3));
	vector B(n,matrix<lint>(3));
	rep(i,n){
		int type; scanf("%d",&type);
		if(type==1){
			int dx; scanf("%d",&dx);
			rep(k,2) A[i][k][k]=B[i][k][k]=1;
			A[i][0][2]=dx;
			B[i][0][2]=-dx;
		}
		else if(type==2){
			int dy; scanf("%d",&dy);
			rep(k,2) A[i][k][k]=B[i][k][k]=1;
			A[i][1][2]=dy;
			B[i][1][2]=-dy;
		}
		else{
			A[i][0][1]=1;
			A[i][1][0]=-1;
			B[i][0][1]=-1;
			B[i][1][0]=1;
		}
		A[i][2][2]=1;
		B[i][2][2]=1;
	}

	auto C=matrix<lint>::identity(3);
	rep(i,n) C=A[i]*C;

	rep(i,n){
		auto v=C*vector<lint>{x0,y0,1};
		printf("%lld %lld\n",v[0],v[1]);
		C*=B[i];
	}

	return 0;
}
