#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class G>
class Fenwick_tree{
	vector<G> a;
public:
	Fenwick_tree(int n):a(n){}
	void add(int i,G val){
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

template<class T> struct interval{
	T l,r;
	int id;
	interval():l(T{}),r(T{}){}
	interval(const T& l,const T& r,int id):l(l),r(r),id(id){}
	bool operator<(const interval& I)const{ return make_tuple(r,-l)<make_tuple(I.r,-I.l); }
};

int main(){
	int n,m,q; scanf("%d%d%d",&n,&m,&q);
	string s; cin>>s;
	vector<interval<int>> I(m);
	rep(i,m){ int l,r; scanf("%d%d",&l,&r); I[i]={l-1,r,i}; }

	vector<int> ans(q+1);
	Fenwick_tree<int> F(n);
	{
		rep(i,n) if(s[i]=='1') F.add(i,1);
		rep(i,m) if(F.sum(I[i].l,I[i].r)>0) ans[0]++;
	}

	vector<interval<int>> J1(q),J2(q),J3(q);
	vector<int> pm(q);
	rep(i,q){
		int x; scanf("%d",&x); x--;

		pm[i]=(s[x]=='0'?1:-1);
		if(pm[i]==-1){ s[x]='0'; F.add(x,-1); }

		int l=F.lower_bound(F.sum(0,x));
		if(s[l]=='1') l++;
		int r=F.upper_bound(F.sum(0,x));
		J1[i]={l,r,i};
		J2[i]={l,x,i};
		J3[i]={x+1,r,i};

		if(pm[i]==1){ s[x]='1'; F.add(x,1); }
	}

	vector<pair<interval<int>,int>> K;
	rep(i,I .size()) K.emplace_back(I[i],-1);
	rep(i,J1.size()) K.emplace_back(J1[i],1);
	rep(i,J2.size()) K.emplace_back(J2[i],2);
	rep(i,J3.size()) K.emplace_back(J3[i],3);
	sort(K.begin(),K.end());

	Fenwick_tree<int> Left(n);
	for(auto p:K){
		auto k=p.first;
		if(p.second<0){
			Left.add(k.l,1);
		}
		else{
			ans[k.id+1]+=pm[k.id]*(p.second==1?1:-1)*Left.sum(k.l,k.r);
		}
	}

	rep(i,q){
		ans[i+1]+=ans[i];
		printf("%d\n",ans[i+1]);
	}

	return 0;
}
