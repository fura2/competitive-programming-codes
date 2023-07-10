#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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

class mint{
	static const int MOD=1e9+7;
	int x;
public:
	mint():x(0){}
	mint(long long y){ x=y%MOD; if(x<0) x+=MOD; }

	mint& operator+=(const mint& m){ x+=m.x; if(x>=MOD) x-=MOD; return *this; }
	mint& operator-=(const mint& m){ x-=m.x; if(x<   0) x+=MOD; return *this; }
	mint& operator*=(const mint& m){ x=(long long)x*m.x%MOD; return *this; }
	mint& operator/=(const mint& m){ return *this*=inverse(m); }
	mint operator+(const mint& m)const{ return mint(*this)+=m; }
	mint operator-(const mint& m)const{ return mint(*this)-=m; }
	mint operator*(const mint& m)const{ return mint(*this)*=m; }
	mint operator/(const mint& m)const{ return mint(*this)/=m; }
	mint operator-()const{ return -x; }

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=t; return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

mint operator+(long long x,const mint& m){ return mint(x)+m; }
mint operator-(long long x,const mint& m){ return mint(x)-m; }
mint operator*(long long x,const mint& m){ return mint(x)*m; }
mint operator/(long long x,const mint& m){ return mint(x)/m; }

mint det(matrix<mint> A){
	assert(A.h()==A.w());
	int n=A.h();

	int sgn=1;
	rep(i,n){
		int piv;
		for(piv=i;piv<n;piv++) if(A[piv][i].to_int()!=0) break;
		if(piv==n) return 0;
		if(piv!=i){
			rep(j,n) swap(A[i][j],A[piv][j]);
			sgn*=-1;
		}
		for(int k=i+1;k<n;k++) if(A[k][i].to_int()!=0) {
			mint c=A[k][i]/A[i][i];
			for(int j=i;j<n;j++) A[k][j]-=c*A[i][j];
		}
	}

	mint res=sgn;
	rep(i,n) res*=A[i][i];
	return res;
}

template<class T>
mint number_of_spanning_trees(matrix<T> A){
	assert(A.h()==A.w());
	int n=A.h();

	matrix<mint> Lap(n-1);
	rep(u,n-1) rep(v,n-1) {
		Lap[u][v]=-A[u][v];
		if(u==v){
			rep(w,n) Lap[u][u]+=A[u][w];
		}
	}
	return det(Lap);
}

int main(){
	int n; scanf("%d",&n);

	matrix<int> A(n);
	rep(i,n) rep(j,n) scanf("%d",&A[i][j]);

	union_find U(n);
	rep(i,n) rep(j,i) if(A[i][j]==1) {
		if(U.is_same(i,j)){
			puts("0");
			return 0;
		}
		U.unite(i,j);
	}

	int k=U.size();
	map<int,int> f;
	rep(i,n) if(f.count(U.find(i))==0) f[U.find(i)]=f.size();

	matrix<int> A2(k);
	rep(i,n) rep(j,n) if(A[i][j]==-1) A2[f[U.find(i)]][f[U.find(j)]]++;
	printf("%d\n",number_of_spanning_trees(A2));

	return 0;
}
