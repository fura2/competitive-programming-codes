#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

class union_find{
	int n;
	vector<int> p;
public:
	union_find(int n):n(n),p(n,-1){}
	int find(int u){ return p[u]<0?u:p[u]=find(p[u]); }
	void unite(int u,int v){
		u=find(u); v=find(v);
		if(u!=v){
			if(p[v]<p[u]) swap(u,v);
			p[u]+=p[v]; p[v]=u; n--;
		}
	}
	bool is_same(int u,int v){ return find(u)==find(v); }
	int size()const{ return n; }
	int size(int u){ return -p[find(u)]; }
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

int main(){
	vector<lint> a(7);
	rep(i,7) scanf("%lld",&a[i]);

	if(a[0]==0){
		puts("NO");
		return 0;
	}
	a[0]--;

	bool odd=false;
	if(accumulate(a.begin(),a.end(),0LL)%2==1){
		odd=true;
		rep(i,7){
			if(a[i]==0){
				puts("NO");
				return 0;
			}
			a[i]--;
		}
	}

	matrix<lint> A(7);
	rep(i,7){
		int sgn=1;
		rep(j,7){
			A[i][(i+j+1)%7]=sgn;
			sgn*=-1;
		}
	}

	auto x=A*a;
	rep(i,7){
		if(x[i]<0 || x[i]%2!=0){
			puts("NO");
			return 0;
		}
		x[i]/=2;
	}

	if(!odd){
		vector<lint> deg(7);
		union_find U(7);
		rep(i,7){
			deg[i]+=x[i];
			deg[(i+1)%7]+=x[i];
			if(x[i]>0) U.unite(i,(i+1)%7);
		}
		rep(i,7) if(deg[i]>0 && !U.is_same(0,i)) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");

	return 0;
}
