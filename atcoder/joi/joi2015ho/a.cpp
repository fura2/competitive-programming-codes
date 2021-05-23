#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class G>
class Fenwick_tree_dual{
	vector<G> a;
public:
	Fenwick_tree_dual(int n):a(n){}
	void add(int l,int r,const G& val){
		if(l==0){
			for(;r>0;r-=r&-r) a[r-1]+=val;
			return;
		}
		add(0,r,val);
		add(0,l,-val);
	}
	G sum(int i)const{
		G res{};
		for(i++;i<=a.size();i+=i&-i) res+=a[i-1];
		return res;
	}
};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> p(m),a(n),b(n),c(n);
	rep(i,m) scanf("%d",&p[i]), p[i]--;
	rep(i,n-1) scanf("%d%d%d",&a[i],&b[i],&c[i]);

	Fenwick_tree_dual<int> F(n-1);
	rep(i,m-1){
		int l=min(p[i],p[i+1]);
		int r=max(p[i],p[i+1]);
		F.add(l,r,1);
	}

	lint ans=0;
	rep(i,n-1){
		lint k=F.sum(i);
		ans+=min(k*a[i],c[i]+k*b[i]);
	}
	printf("%lld\n",ans);

	return 0;
}
