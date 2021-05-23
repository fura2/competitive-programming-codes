#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

class starry_sky_tree{
	int n;
	vector<int> dat1,dat2;

	void add(int l,int r,int a,int b,int u,int val){
		if(b<=l || r<=a) return;
		if(l<=a && b<=r){ dat1[u]+=val; return; }

		add(l,r,a,(a+b)/2,2*u+1,val);
		add(l,r,(a+b)/2,b,2*u+2,val);

		dat2[u]=max(dat2[2*u+1]+dat1[2*u+1],dat2[2*u+2]+dat1[2*u+2]);
	}

	int query_max(int l,int r,int a,int b,int u){
		if(b<=l || r<=a) return 0;
		if(l<=a && b<=r) return dat1[u]+dat2[u];

		int res1=query_max(l,r,a,(a+b)/2,2*u+1);
		int res2=query_max(l,r,(a+b)/2,b,2*u+2);
		return max(res1,res2)+dat1[u];
	}

public:
	starry_sky_tree(int N){
		for(n=1;n<N;n*=2);
		dat1.assign(2*n,0);
		dat2.assign(2*n,0);
	}

	void add(int l,int r,int val){ add(l,r,0,n,0,val); }

	int query_max(int l,int r){ return query_max(l,r,0,n,0); }
};

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
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	bool sorted=true,same=false;
	rep(i,n-1){
		if(a[i]>a[i+1]) sorted=false;
		if(a[i]==a[i+1]) same=true;
	}
	if(sorted){
		puts(same?"0":"1");
		return 0;
	}

	vector<int> TL,BR,Mid; // top left, bottom right, neither
	rep(i,n-1) if(TL.empty() || a[TL.back()]<a[i]) {
		TL.emplace_back(i);
	}
	for(int i=n-1;i>0;i--) if(BR.empty() || a[BR.back()]>a[i]) {
		BR.emplace_back(i);
	}
	reverse(BR.begin(),BR.end());
	rep(i,n){
		if(!binary_search(TL.begin(),TL.end(),i)
		&& !binary_search(BR.begin(),BR.end(),i)) Mid.emplace_back(i);
	}

	int m=Mid.size();
	vector<int> left(m),right(m); // Mid[i] は TL[left[i],right[i]) に寄与
	vector<bool> eq(m); // eq[i] が true なら, Mid[i] は TL[left[i]-1] にも 1 点分として寄与
	rep(i,m){
		int lo=-1,hi=TL.size();
		while(hi-lo>1){
			int mi=(lo+hi)/2;
			if(a[TL[mi]]>a[Mid[i]]) hi=mi;
			else                    lo=mi;
		}
		left[i]=hi;
		right[i]=lower_bound(TL.begin(),TL.end(),Mid[i])-TL.begin();
		right[i]=max(right[i],left[i]);

		if(left[i]>0 && a[TL[left[i]-1]]==a[Mid[i]]) eq[i]=true;
	}

	int res=0,idx=0;
	priority_queue<pair<int,int>> Q1,Q2; // 注目している長方形に含まれる Mid の点
	starry_sky_tree S(TL.size());

	for(int i:BR){
		while(idx<m && Mid[idx]<i){
			if(a[Mid[idx]]>a[i]){
				S.add(left[idx],right[idx],2);
				if(eq[idx]) S.add(left[idx]-1,left[idx],1);
				Q2.emplace(-a[Mid[idx]],idx);
			}
			else if(a[Mid[idx]]==a[i]){
				S.add(left[idx],right[idx],1);
				Q1.emplace(-a[Mid[idx]],idx);
			}
			idx++;
		}

		while(!Q2.empty() && -Q2.top().first<=a[i]){
			int a2=-Q2.top().first;
			int k=Q2.top().second;
			Q2.pop();
			S.add(left[k],right[k],-2);
			if(eq[k]) S.add(left[k]-1,left[k],-1);
			if(a2==a[i]){
				S.add(left[k],right[k],1);
				Q1.emplace(-a[Mid[k]],k);
			}
		}

		while(!Q1.empty() && -Q1.top().first<a[i]){
			int k=Q1.top().second;
			Q1.pop();
			S.add(left[k],right[k],-1);
		}

		res=max(res,S.query_max(0,TL.size()));
	}

	printf("%lld\n",inversion_number(a)-(res+1));

	return 0;
}
