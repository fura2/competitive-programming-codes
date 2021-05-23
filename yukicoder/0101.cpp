#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

class permutation{
	vector<int> f;
public:
	permutation(){}
	permutation(int n){
		f.resize(n);
		iota(f.begin(),f.end(),0);
	}
	permutation(const vector<int>& p):f(p){}

	permutation operator*(const permutation& p)const{
		int n=f.size();
		permutation res(n);
		rep(i,n) res.f[i]=f[p[i]];
		return res;
	}
	int operator[](int i)const{ return f[i]; }

	int size()const{ return f.size(); }

	void swap(int i,int j){ std::swap(f[i],f[j]); }

	friend permutation inverse(const permutation& p){
		int n=p.f.size();
		permutation res(n);
		rep(i,n) res.f[p.f[i]]=i;
		return res;
	}
};

vector<vector<int>> find_cycles(const vector<int>& f){
	int n=f.size();
	vector<vector<int>> Res;
	vector<int> color(n,-1);
	rep(u,n) if(color[u]==-1) {
		int v=u;
		do{ color[v]=u; v=f[v]; }while(color[v]==-1);
		if(color[v]==u){
			vector<int> C;
			int w=v;
			do{ C.emplace_back(v); v=f[v]; }while(v!=w);
			Res.emplace_back(C);
		}
	}
	return Res;
}

template<class T> T gcd(const T& a,const T& b){ return b==0?a:gcd(b,a%b); }
template<class T> T lcm(const T& a,const T& b){ return a/gcd(a,b)*b; }

int main(){
	int n,k; scanf("%d%d",&n,&k);
	permutation p(n);
	rep(i,k){
		int x; scanf("%d%*d",&x); x--;
		p.swap(x,x+1);
	}

	vector<int> f(n);
	rep(i,n) f[i]=p[i];

	lint ans=1;
	for(auto C:find_cycles(f)) ans=lcm<lint>(ans,C.size());
	printf("%lld\n",ans);

	return 0;
}
