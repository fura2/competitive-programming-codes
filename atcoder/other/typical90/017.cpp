#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

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
	int n,m; scanf("%d%d",&n,&m);
	vector<int> l(m),r(m);
	rep(i,m) scanf("%d%d",&l[i],&r[i]), l[i]--, r[i]--;

	// naive solution
	/*
	lint ans=0;
	for(int i=m-1;i>=0;i--){
		for(int j=i+1;j<m;j++){
			if(l[i]<l[j] && l[j]<r[i] && (r[j]<l[i] || r[i]<r[j])) ans++;
		}
	}
	printf("%lld\n",ans);
	*/

	vector<tuple<int,int,int>> Ev;
	rep(i,m){
		Ev.emplace_back(l[i],i,0);
		Ev.emplace_back(r[i]-1,i,1);
	}
	sort(Ev.begin(),Ev.end());

	lint ans=0;
	Fenwick_tree<int> F(n);
	for(int t=2*m-1;;t--){
		auto [x,i,type]=Ev[t];
		if(type==0){
			ans+=F.sum(0,l[i])+F.sum(r[i]+1,n);
		}
		else{
			ans-=F.sum(0,l[i])+F.sum(r[i]+1,n);
		}

		if(t==0) break;
		int x_next=get<0>(Ev[t-1]);
		if(x_next<x){
			for(int t2=t;t2<2*m;t2++){
				auto [x2,i2,type2]=Ev[t2];
				if(x2>x) break;
				if(type2==0) F.add(r[i2],1);
			}
		}
	}
	printf("%lld\n",ans);

	return 0;
}
