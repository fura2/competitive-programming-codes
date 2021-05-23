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
		for(int i=1;i<a.size();i++) (this->a)[i+(i&-i)-1]+=(this->a)[i-1];
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
	int lower_bound(const G& val)const{
		if(val<=G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<val) val-=a[x+k-1], x+=k;
		return x;
	}
	int upper_bound(const G& val)const{
		if(val<G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<=val) val-=a[x+k-1], x+=k;
		return x;
	}
};

int main(){
	int q; scanf("%d",&q);
	vector<int> type(q),x(q),y(q);
	rep(i,q) scanf("%d%d%d",&type[i],&x[i],&y[i]);

	auto X=x;
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());

	lint ans=0;
	Fenwick_tree<lint> F(X.size());
	rep(i,q){
		if(type[i]==0){
			int pos=lower_bound(X.begin(),X.end(),x[i])-X.begin();
			F.add(pos,y[i]);
		}
		else{
			int l=lower_bound(X.begin(),X.end(),x[i])-X.begin();
 			if(l==X.size()) continue;
			int r=upper_bound(X.begin(),X.end(),y[i])-X.begin();
			ans+=F.sum(l,r);
		}
	}
	printf("%lld\n",ans);

	return 0;
}
