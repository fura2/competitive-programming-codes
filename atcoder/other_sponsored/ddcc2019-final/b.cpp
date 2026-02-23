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
	lint n,k,tar; scanf("%lld%lld%lld",&n,&k,&tar);

	if(tar>(n-k)*(n-k+1)/2){
		puts("No Luck");
		return 0;
	}

	lint sum=(n-k)*(n-k+1)/2; // 得られるスコアの最大値
	Fenwick_tree<int> F(vector<int>(n,1)); // F[i] = 1 : i は未使用, 0 : i は使用済み
	rep(i,n){
		int lo=0,hi=n-i;
		while(hi-lo>1){
			int mi=(lo+hi)/2;
			int x=F.lower_bound(mi+1);

			lint cnt=sum;
			if(x+k<n) cnt-=F.sum(x+k,n);
			if(cnt<=tar) lo=mi;
			else         hi=mi;
		}

		int x=F.lower_bound(lo+1);
		F.add(x,-1);
		if(x+k<n) sum-=F.sum(x+k,n);

		printf("%d%c",x+1,i<n-1?' ':'\n');
	}

	return 0;
}
