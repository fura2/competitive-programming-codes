#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class G>
class Fenwick_tree_dual{
	vector<G> a;
public:
	Fenwick_tree_dual(int n):a(n){}
	void add(int l,int r,G val){
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
	vector<int> x0(n),y0(n),d(n),c(n);
	rep(i,n) scanf("%d%d%d%d",&x0[i],&y0[i],&d[i],&c[i]);
	vector<int> a(q),b(q);
	rep(i,q) scanf("%d%d",&a[i],&b[i]);

	vector<int> Y;
	rep(i,n){
		Y.emplace_back(y0[i]);
		Y.emplace_back(y0[i]+d[i]+1);
	}
	rep(i,q){
		Y.emplace_back(b[i]);
	}
	sort(Y.begin(),Y.end());
	Y.erase(unique(Y.begin(),Y.end()),Y.end());

	const int OFSET=1e5;
	vector<pair<int,int>> Ev;
	rep(i,n){
		Ev.emplace_back(x0[i],i+OFSET);
		Ev.emplace_back(x0[i]+d[i]+1,i);
	}
	rep(i,q){
		Ev.emplace_back(a[i],i+2*OFSET);
	}
	sort(Ev.begin(),Ev.end());

	vector<lint> ans(q);
	Fenwick_tree_dual<lint> F(Y.size());
	for(auto e:Ev){
		int id=e.second;
		if(id<OFSET){ // square right
			int l=lower_bound(Y.begin(),Y.end(),y0[id])-Y.begin();
			int r=lower_bound(Y.begin(),Y.end(),y0[id]+d[id]+1)-Y.begin();
			F.add(l,r,-c[id]);
		}
		else if(id<2*OFSET){ // square left
			id%=OFSET;
			int l=lower_bound(Y.begin(),Y.end(),y0[id])-Y.begin();
			int r=lower_bound(Y.begin(),Y.end(),y0[id]+d[id]+1)-Y.begin();
			F.add(l,r,c[id]);
		}
		else{ // query
			id%=OFSET;
			int p=lower_bound(Y.begin(),Y.end(),b[id])-Y.begin();
			ans[id]=F.sum(p);
		}
	}

	rep(i,q) printf("%lld\n",ans[i]);

	return 0;
}
