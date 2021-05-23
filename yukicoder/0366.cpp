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

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<vector<int>> b(k);
	rep(i,n) b[i%k].emplace_back(a[i]);

	int ans=0;
	rep(i,k) ans+=inversion_number(b[i]);

	rep(i,k) sort(b[i].begin(),b[i].end());
	rep(i,k) rep(j,b[i].size()) a[i+k*j]=b[i][j];
	bool sorted=true;
	rep(i,n-1) if(a[i]>a[i+1]) sorted=false;

	printf("%d\n",sorted?ans:-1);

	return 0;
}
