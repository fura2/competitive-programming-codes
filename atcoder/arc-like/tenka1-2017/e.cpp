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

template<class T>
long long inversion_number(const vector<T>& a){
	auto X=a;
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());

	long long res=0;
	Fenwick_tree<int> F(X.size());
	rep(i,a.size()){
		int x=lower_bound(X.begin(),X.end(),a[i])-X.begin();
		res+=F.sum(x+1,X.size());
		F.add(x,1);
	}
	return res;
}

double solve(vector<int> A,vector<int> B,vector<int> C){
	int n=A.size();
	vector<pair<double,double>> L(n); // (傾き, 切片)
	rep(i,n){
		L[i]={-1.0*A[i]/B[i],1.0*C[i]/B[i]};
	}
	sort(L.begin(),L.end());

	double lo=-1e9,hi=1e9;
	rep(_,70){
		double mi=(lo+hi)/2;

		vector<pair<double,int>> Y(n);
		rep(i,n){
			auto [a,b]=L[i];
			Y[i]={a*mi+b,i};
		}
		sort(Y.begin(),Y.end(),greater<>());

		// p[i] = (n 本の直線を x = mi における y 座標の大きい順に並べたとき, 直線 i は何番目か)
		vector<int> p(n);
		rep(i,n) p[Y[i].second]=i;

		int cnt=inversion_number(p); // x <= mi にある交点の個数
		if(cnt<(n*(n-1)/2+1)/2) lo=mi;
		else                    hi=mi;
	}
	return lo;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n),c(n);
	rep(i,n) scanf("%d%d%d",&a[i],&b[i],&c[i]);

	double ans[2];
	rep(i,2){
		ans[i]=solve(a,b,c);
		rep(j,n) swap(a[j],b[j]);
	}
	printf("%.15f %.15f\n",ans[0],ans[1]);

	return 0;
}
