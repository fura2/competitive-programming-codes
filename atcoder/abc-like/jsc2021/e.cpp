#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class union_find{
	int n;
	vector<int> p;
public:
	union_find(int n):n(n),p(n,-1){}
	int find(int u){ return p[u]<0?u:p[u]=find(p[u]); }
	void unite(int u,int v){
		u=find(u); v=find(v);
		if(u!=v){
			if(p[v]<p[u]) swap(u,v);
			p[u]+=p[v]; p[v]=u; n--;
		}
	}
	bool is_same(int u,int v){ return find(u)==find(v); }
	int size()const{ return n; }
	int size(int u){ return -p[find(u)]; }
};

bool ispali(string s){
	string t=s;
	reverse(t.begin(),t.end());
	return s==t;
}

string s;
union_find U(0);
int R;

bool dfs(int l,int r,int k){
	int n=r-l;

	if(k==0){
		if(l==0) R=r;
		if(n==0) return true;
		if(n==1) return false;
		return true;		
	}

	if(n==0) return false;

	rep(i,n/2) U.unite(i,n-i-1);

	return dfs(l,l+n/2,k-1) && dfs(l+n/2+n%2,r,k-1);
}

int main(){
	int k;
	cin>>k>>s;
	int n=s.length();

	U=union_find(n);
	if(!dfs(0,s.length(),k)){
		puts("impossible");
		return 0;
	}

	vector C(n,vector<int>());
	rep(i,n) C[U.find(i)].emplace_back(i);

	int ans=0;
	string t(n,'?');
	rep(id,n) if(!C[id].empty()) {
		map<char,int> f;
		for(auto i:C[id]) ++f[s[i]];
		char c_max;
		int val_max=0;
		for(auto [c,val]:f){
			if(val_max<val){
				c_max=c;
				val_max=val;
			}
		}
		ans+=C[id].size()-val_max;
		for(int i:C[id]) t[i]=c_max;
	}
	if(R>0 && ispali(t.substr(0,R))){
		int dif_min=n;
		rep(i,R) if(!(R%2==1 && i==R/2)) {
			int id=U.find(i);

			map<char,int> f;
			for(auto i:C[id]) ++f[s[i]];
			int val_max1=0,val_max2=0;
			for(auto [c,val]:f){
				if(val_max1<val){
					val_max2=val_max1;
					val_max1=val;
				}
				else if(val_max2<val){
					val_max2=val;
				}
			}
			dif_min=min(dif_min,val_max1-val_max2);
		}
		ans+=dif_min;
	}
	printf("%d\n",ans);

	return 0;
}
