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
	int h,w,q; scanf("%d%d%d",&h,&w,&q);
	vector<int> type(q),p(q);
	vector<lint> val(q);
	rep(i,q) scanf("%d%d%lld",&type[i],&p[i],&val[i]), p[i]--;

	vector<int> idx(q);
	{
		vector<pair<lint,int>> P(q+1);
		rep(i,q) P[i]={val[i],i};
		P[q]={0,-1};
		sort(P.begin(),P.end());
		rep(i,q+1) if(P[i].second!=-1) idx[P[i].second]=i;
	}

	Fenwick_tree<lint> Frow_cnt(q+1),Frow_sum(q+1);
	Fenwick_tree<lint> Fcol_cnt(q+1),Fcol_sum(q+1);
	Frow_cnt.add(0,h);
	Fcol_cnt.add(0,w);

	lint sum=0;
	vector<int> pre_row(h,0),pre_col(w,0);
	rep(i,q){
		if(type[i]==1){
			int pre=pre_row[p[i]];
			int val_pre=Frow_sum.sum(pre,pre+1);

			sum-=val_pre*Fcol_cnt.sum(0,pre)-Fcol_sum.sum(0,pre);
			sum+=val[i]*Fcol_cnt.sum(0,idx[i])-Fcol_sum.sum(0,idx[i]);

			Frow_cnt.add(idx[i],1);
			Frow_sum.add(idx[i],val[i]);
			if(pre!=-1){
				Frow_cnt.add(pre,-1);
				Frow_sum.add(pre,-val_pre);
			}
			pre_row[p[i]]=idx[i];
		}
		else{
			int pre=pre_col[p[i]];
			int val_pre=Fcol_sum.sum(pre,pre+1);

			sum-=val_pre*Frow_cnt.sum(0,pre)-Frow_sum.sum(0,pre);
			sum+=val[i]*Frow_cnt.sum(0,idx[i])-Frow_sum.sum(0,idx[i]);

			Fcol_cnt.add(idx[i],1);
			Fcol_sum.add(idx[i],val[i]);
			if(pre!=-1){
				Fcol_cnt.add(pre,-1);
				Fcol_sum.add(pre,-val_pre);
			}
			pre_col[p[i]]=idx[i];
		}
		printf("%lld\n",sum);
	}

	return 0;
}
