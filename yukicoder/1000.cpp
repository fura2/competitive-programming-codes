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
	int n,q; scanf("%d%d",&n,&q);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);
	vector<char> type(q);
	vector<int> x(q),y(q);
	rep(i,q) scanf(" %c%d%d",&type[i],&x[i],&y[i]), x[i]--;

	Fenwick_tree_dual<int> F(n);
	rep(i,q) if(type[i]=='B') F.add(x[i],y[i],1);

	vector<lint> res(n);
	rep(i,n) res[i]+=a[i]*F.sum(i);
	rep(i,q){
		if(type[i]=='A'){
			res[x[i]]+=lint(y[i])*F.sum(x[i]);
		}
		else{
			F.add(x[i],y[i],-1);
		}
	}
	rep(i,n) printf("%lld%c",res[i],i<n-1?' ':'\n');

	return 0;
}
