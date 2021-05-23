#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

class rolling_hash{
	static const long long base=10007,mod1=1e9+7,mod2=1e9+9;
	int len;
	vector<long long> pow1,pow2,h1,h2;
public:
	using hash_type=pair<long long,long long>;
	rolling_hash(const string& s):len(s.length()),pow1(len+1),pow2(len+1),h1(len+1),h2(len+1){
		pow1[0]=pow2[0]=1;
		rep(i,len){
			pow1[i+1]=pow1[i]*base%mod1;
			pow2[i+1]=pow2[i]*base%mod2;
			h1[i+1]=(h1[i]*base+s[i])%mod1;
			h2[i+1]=(h2[i]*base+s[i])%mod2;
		}
	}
	hash_type get_hash(int l,int r)const{
		assert(0<=l && l<=r && r<=len);
		auto res1=(h1[r]-h1[l]*pow1[r-l])%mod1; if(res1<0) res1+=mod1;
		auto res2=(h2[r]-h2[l]*pow2[r-l])%mod2; if(res2<0) res2+=mod2;
		return {res1,res2};
	}
	static hash_type get_hash(const string& s){
		long long res1=0,res2=0;
		rep(i,s.length()){
			res1=(res1*base+s[i])%mod1;
			res2=(res2*base+s[i])%mod2;
		}
		return {res1,res2};
	}
};

int main(){
	string s; cin>>s;
	int n=s.length();
	rolling_hash H(s);

	map<rolling_hash::hash_type,int> f;
	rep(d,min(n,10)+1) rep(i,n-d+1) ++f[H.get_hash(i,i+d)];

	int ans=0,q; cin>>q;
	rep(_,q){
		string t; cin>>t;
		ans+=f[rolling_hash::get_hash(t)];
	}
	cout<<ans<<'\n';

	return 0;
}
