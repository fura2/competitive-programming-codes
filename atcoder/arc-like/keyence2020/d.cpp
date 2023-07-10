#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

inline int popcount(int x){
	x=((x>>1)&0x55555555)+(x&0x55555555);
	x=((x>>2)&0x33333333)+(x&0x33333333);
	x=((x>>4)+x)&0x0f0f0f0f;
	x+=(x>>8);
	x+=(x>>16);
	return x&0x3f;
}

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

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]);

	int ans=INF;
	rep(S,1<<n) if(popcount(S)==(n+1)/2) {
		int ne=0,no=0;
		pair<int,int> even[9],odd[9];
		rep(i,n){
			if(S>>i&1) even[ne++]={i%2==0?a[i]:b[i],i};
			else       odd [no++]={i%2==1?a[i]:b[i],i};
		}

		sort(even,even+ne);
		sort(odd ,odd +no);

		bool ok=true;
		rep(i,ne) if( i <no && even[i].first>odd [ i ].first) ok=false;
		rep(i,no) if(i+1<ne && odd [i].first>even[i+1].first) ok=false;
		if(!ok) continue;

		vector<int> p(n);
		rep(i,n) p[i]=(i%2==0?even:odd)[i/2].second;

		ans=min(ans,(int)inversion_number(p));
	}
	printf("%d\n",ans<INF?ans:-1);

	return 0;
}
