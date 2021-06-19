#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class M>
M pow(M f,long long k){
	M res;
	for(;k>0;k>>=1){
		if(k&1) res=res*f;
		f=f*f;
	}
	return res;
}

class endomorphism_monoid{
	vector<int> f;
public:
	endomorphism_monoid(){}
	endomorphism_monoid(const vector<int>& f):f(f){}
	endomorphism_monoid operator*(const endomorphism_monoid& a)const{
		int n=f.size(),m=a.f.size();
		int k=max(n,m);
		vector<int> res(k);
		rep(i,k){
			int x=(i<m?a.f[i]:i);
			res[i]=(x<n?f[x]:x);
		}
		return res;
	}
	int operator[](int i)const{ return i<f.size()?f[i]:i; }
};

int digitsum(int n){
	int res=0;
	for(;n>0;n/=10) res+=n%10;
	return res;
}

int main(){
	int n;
	lint k; scanf("%d%lld",&n,&k);

	vector<int> f(1e5);
	rep(i,1e5) f[i]=(i+digitsum(i))%100000;

	printf("%d\n",pow(endomorphism_monoid(f),k)[n]);

	return 0;
}
