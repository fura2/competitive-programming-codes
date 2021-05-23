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
	int n,q; scanf("%d%d",&n,&q);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	Fenwick_tree<lint> F1=a;

	Fenwick_tree<int> F2(vector<int>(n,1));
	F2.add(0,-1);
	rep(_,q){
		int type,x; scanf("%d%d",&type,&x);
		if(type==1){
			if(F2.sum(x,x+1)==1) F2.add(x,-1);
		}
		else if(type==2){
			if(F2.sum(x,x+1)==0) F2.add(x,1);
		}
		else if(type==3){
			F1.add(x-1,1);
		}
		else{
			int k=F2.sum(0,x);
			int l=F2.lower_bound(k);
			int r=F2.lower_bound(k+1);
			printf("%lld\n",F1.sum(l,r));
		}
	}

	return 0;
}
