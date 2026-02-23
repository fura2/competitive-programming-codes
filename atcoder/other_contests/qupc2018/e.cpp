#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

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
	G get(int i)const{
		G res{};
		for(i++;i<=a.size();i+=i&-i) res+=a[i-1];
		return res;
	}
};

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	map<lint,vector<int>> Pos;
	lint cum=0;
	rep(i,n+1){
		Pos[cum].emplace_back(i);
		if(i<n) cum+=a[i];
	}

	lint ans=0;
	Fenwick_tree_dual<lint> F(n);
	for(auto p:Pos){
		lint len=p.second.size();
		ans+=len*(len-1)/2;
		rep(i,len-1){
			F.add(p.second[i],p.second[i+1],(i+1)*(len-i-1));
		}
	}

	lint mx=0;
	rep(i,n) mx=max(mx,F.get(i));
	ans-=mx;

	printf("%lld\n",ans);

	return 0;
}
