#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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

const int INF=1<<29;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<pair<int,int>> s[4];
	rep(i,n){
		int x,a,b; scanf("%d%d%d",&x,&a,&b);
		s[x].emplace_back(a,b);
	}

	if(s[2].size()+s[3].size()>=m){
		printf("%ld\n",s[3].size());
		return 0;
	}

	rep(x,4) sort(s[x].rbegin(),s[x].rend());

	Fenwick_tree<int> F[4];
	rep(x,4){
		F[x].build(1e5+2);
		for(auto p:s[x]) F[x].add(p.second,1);
	}

	int ans=INF,idx[3]={};
	for(int a=1e5+1;a>=0;a--){
		rep(x,3){
			while(idx[x]<s[x].size() && s[x][idx[x]].first>=a){
				F[x].add(s[x][idx[x]].second,-1);
				F[x+1].add(s[x][idx[x]].second,1);
				idx[x]++;
			}
		}

		int F2_total=F[2].sum(0,1e5+2);
		int F3_total=F[3].sum(0,1e5+2);
		if(F[1].sum(0,1e5+2)+F2_total+F3_total<m) continue;

		int lo=0,hi=1e5+2;
		while(hi-lo>1){
			int mi=(lo+hi)/2;
			if(F[1].sum(mi,1e5+2)+F2_total+F3_total>=m) lo=mi; else hi=mi;
		}
		ans=min(ans,F[2].sum(lo,1e5+2)+F3_total);
	}
	printf("%d\n",ans);

	return 0;
}
