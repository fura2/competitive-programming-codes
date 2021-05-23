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
	int n,q,s,t; scanf("%d%d%d%d",&n,&q,&s,&t);
	n++;

	Fenwick_tree_dual<lint> F(n);
	rep(i,n){
		lint a; scanf("%lld",&a);
		F.add(i,i+1,a);
	}

	auto calc=[&](int i){
		lint x=F.sum(i),y=F.sum(i+1);
		if(x<y) return s*(x-y);
		else    return t*(x-y);
	};

	lint ans=0;
	rep(i,n-1) ans+=calc(i);

	rep(_,q){
		int l,r,x; scanf("%d%d%d",&l,&r,&x); r++;
		if(l>0) ans-=calc(l-1);
		if(r<n) ans-=calc(r-1);
		F.add(l,r,x);
		if(l>0) ans+=calc(l-1);
		if(r<n) ans+=calc(r-1);
		printf("%lld\n",ans);
	}

	return 0;
}
