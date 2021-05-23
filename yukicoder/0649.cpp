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
	int q,k; scanf("%d%d",&q,&k);
	vector<int> type(q);
	vector<lint> a(q);
	rep(i,q){
		scanf("%d",&type[i]);
		if(type[i]==1) scanf("%lld",&a[i]);
	}

	vector<lint> X=a;
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	rep(i,q) a[i]=lower_bound(X.begin(),X.end(),a[i])-X.begin();

	Fenwick_tree<int> F(X.size());
	rep(i,q){
		if(type[i]==1){
			F.add(a[i],1);
		}
		else{
			int res=F.lower_bound(k);
			if(res<X.size()){
				printf("%lld\n",X[res]);
				F.add(res,-1);
			}
			else puts("-1");
		}
	}

	return 0;
}
