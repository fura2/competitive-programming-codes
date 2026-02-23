#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

class union_find{
	int n;
	vector<int> p;
public:
	union_find(int n=0){ build(n); }
	void build(int n){
		this->n=n;
		p.assign(n,-1);
	}
	int find(int u){ return p[u]<0?u:p[u]=find(p[u]); }
	void unite(int u,int v){
		u=find(u); v=find(v);
		if(u!=v){
			if(p[v]<p[u]) swap(u,v);
			p[u]+=p[v]; p[v]=u; n--;
		}
	}
	bool is_same(int u,int v){ return find(u)==find(v); }
	int size()const{ return n; }
	int size(int u){ return -p[find(u)]; }
};

template<class G>
class Fenwick_tree{
	vector<G> a;
public:
	Fenwick_tree(int n=0){ build(n); }
	Fenwick_tree(const vector<G>& a){ build(a); }
	void build(int n){
		a.assign(n,G{});
	}
	void build(const vector<G>& a){
		this->a=a;
		for(int i=1;i<=a.size();i++) if(i+(i&-i)<=a.size()) (this->a)[i+(i&-i)-1]+=(this->a)[i-1];
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
		if(!(G{}<val)) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<val) val-=a[x+k-1], x+=k;
		return x;
	}
	int upper_bound(G val)const{
		if(val<G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && !(val<a[x+k-1])) val-=a[x+k-1], x+=k;
		return x;
	}
};

int main(){
	int n,q; scanf("%d%d",&n,&q);

	union_find U(n);
	Fenwick_tree<lint> F(n-1);
	rep(_,q){
		int type,x,y;
		lint v; scanf("%d%d%d%lld",&type,&x,&y,&v); x--; y--;
		if(type==0){
			if(!U.is_same(x,y)){
				U.unite(x,y);
				F.add(x,x%2==0?v:-v);
			}
		}
		else{
			if(!U.is_same(x,y)){
				puts("Ambiguous");
			}
			else{
				lint ans;
				if(x%2==0){
					if(y%2==0){
						ans=v+(x<y?-1:1)*F.sum(min(x,y),max(x,y));
					}
					else{
						ans=-v+(x<y?1:-1)*F.sum(min(x,y),max(x,y));
					}
				}
				else{
					if(y%2==0){
						ans=-v+(x<y?-1:1)*F.sum(min(x,y),max(x,y));
					}
					else{
						ans=v+(x<y?1:-1)*F.sum(min(x,y),max(x,y));
					}
				}
				printf("%lld\n",ans);
			}
		}
	}

	return 0;
}
