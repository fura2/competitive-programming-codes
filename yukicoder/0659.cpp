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

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int main(){
	int h,w,l; scanf("%d%d%d",&h,&w,&l);
	int sy,sx,gy,gx; scanf("%d%d%d%d",&sy,&sx,&gy,&gx);
	char B[10][11];
	rep(i,h) scanf("%s",B[i]);

	matrix<double> A(h*w);
	rep(i,h) rep(j,w) if(B[i][j]=='.') {
		int cnt=0;
		rep(k,4){
			int y=i+dy[k],x=j+dx[k];
			if(0<=y && y<h && 0<=x && x<w && B[y][x]=='.') cnt++;
		}
		if(cnt>0){
			rep(k,4){
				int y=i+dy[k],x=j+dx[k];
				if(0<=y && y<h && 0<=x && x<w && B[y][x]=='.'){
					A[y*w+x][i*w+j]+=1.0/cnt;
				}
			}
		}
		else{
			A[i*w+j][i*w+j]=1;
		}
	}
	printf("%.9f\n",pow(A,l)[gy*w+gx][sy*w+sx]);

	return 0;
}
