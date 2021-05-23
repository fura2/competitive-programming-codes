// Day 4: Typhoon

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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
	int n,q,k; scanf("%d%d%d",&n,&q,&k);
	vector<int> l(n),r(n);
	rep(i,n) scanf("%d%d",&l[i],&r[i]), l[i]--;
	vector<int> p(q),a(q),b(q);
	rep(i,q) scanf("%d%d%d",&p[i],&a[i],&b[i]), p[i]--, a[i]--;

	vector<int> X=p;
	rep(i,n){
		X.emplace_back(l[i]);
		X.emplace_back(r[i]);
	}
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());

	k=X.size();
	rep(i,n){
		l[i]=lower_bound(X.begin(),X.end(),l[i])-X.begin();
		r[i]=lower_bound(X.begin(),X.end(),r[i])-X.begin();
	}
	rep(i,q){
		p[i]=lower_bound(X.begin(),X.end(),p[i])-X.begin();
	}

	vector Ev(n+1,vector<int>());
	rep(i,q){
		Ev[a[i]].emplace_back(-(i+1));
		Ev[b[i]].emplace_back(+(i+1));
	}

	vector<int> ans(n);
	Fenwick_tree_dual<int> F(k);
	rep(i,n){
		F.add(l[i],r[i],1);
		for(auto e:Ev[i+1]){
			int j=abs(e)-1;
			if(e>0) ans[j]+=F.sum(p[j]);
			else    ans[j]-=F.sum(p[j]);
		}
	}
	rep(i,q) printf("%d\n",ans[i]);

	return 0;
}
