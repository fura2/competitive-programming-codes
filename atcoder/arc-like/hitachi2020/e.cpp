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

matrix<int> Hadamard(int n){
	matrix<int> H(1<<n);
	H[0][0]=1;
	rep(k,n){
		int d=1<<k;
		rep(i,d) rep(j,d) {
			H[i][j+d]=H[i][j];
			H[i+d][j]=H[i][j];
			H[i+d][j+d]=-H[i][j];
		}
	}
	return H;
}

int main(){
	int m,n; scanf("%d%d",&m,&n);

	int k=max(m,n);
	auto H=Hadamard(k);

	int N=1<<k;
	// 1 列目をすべて 1 にする
	rep(i,N) if(H[i][0]==-1) {
		rep(j,N) H[i][j]*=-1;
	}
	// 1 行目をすべて 1 にする
	rep(j,N) if(H[0][j]==-1) {
		rep(i,N) H[i][j]*=-1;
	}

	// H の要素 1, -1 を 0, 1 に変換
	rep(i,N) rep(j,N) {
		if(H[i][j]==1) H[i][j]=0;
		else           H[i][j]=1;
	}

	// 差分をとる
	rep(i,N){
		for(int j=N-1;j>0;j--){
			H[i][j]-=H[i][j-1];
		}
	}
	rep(j,N){
		for(int i=N-1;i>0;i--){
			H[i][j]-=H[i-1][j];
		}
	}
	rep(i,N) rep(j,N) H[i][j]&=1;

	rep(i,(1<<m)-1){
		rep(j,(1<<n)-1){
			printf("%d",H[i+1][j+1]);
		}
		puts("");
	}

	return 0;
}
