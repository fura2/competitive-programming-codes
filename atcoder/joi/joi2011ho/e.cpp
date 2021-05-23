#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class G>
class Fenwick_tree{
	vector<G> a;
public:
	Fenwick_tree(){}
	Fenwick_tree(int n){ build(n); }
	Fenwick_tree(const vector<G>& a){ build(a); }
	void build(int n){
		a.assign(n,G{});
	}
	void build(const vector<G>& a){
		this->a=a;
		for(int i=1;i<a.size();i++) if(i+(i&-i)-1<a.size()) (this->a)[i+(i&-i)-1]+=(this->a)[i-1];
	}
	void add(int i,const G& val){
		for(i++;i<=a.size();i+=i&-i) a[i-1]+=val;
	}
	G sum(int l,int r)const{
		if(l==0){
			G res{};
			for(;r>0;r-=r&-r) res+=a[r-1];
			return res;
		}
		return sum(0,r)-sum(0,l);
	}
	int lower_bound(G val)const{
		if(val<=G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<val) val-=a[x+k-1], x+=k;
		return x;
	}
	int upper_bound(G val)const{
		if(val<G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<=val) val-=a[x+k-1], x+=k;
		return x;
	}
};

int main(){
	int n; scanf("%d",&n);
	vector<pair<int,int>> p(n);
	rep(i,n) scanf("%d%d",&p[i].first,&p[i].second);

	sort(p.begin(),p.end(),[](auto x,auto y){
		return x.second>y.second;
	});

	vector<int> ord(n),inv(n);
	iota(ord.begin(),ord.end(),0);
	sort(ord.begin(),ord.end(),[&](int i,int j){
		return p[i].first<p[j].first;
	});
	rep(i,n) inv[ord[i]]=i;

	int lo=0,hi=n+1;
	while(hi-lo>1){
		int mi=(lo+hi)/2;

		bool ok=false;
		Fenwick_tree<int> F1(n);
		Fenwick_tree<lint> F2(n);
		rep(i,n){
			auto [a,b]=p[i];
			F1.add(inv[i],1);
			F2.add(inv[i],a);
			if(i+1>=mi && F2.sum(0,F1.upper_bound(mi))<=lint(mi)*b){
				ok=true;
				break;
			}
		}
		if(ok) lo=mi; else hi=mi;
	}
	printf("%d\n",lo);

	return 0;
}
