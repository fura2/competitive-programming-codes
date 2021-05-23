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
	rolling_hash(){}
	rolling_hash(const string& s):len(s.length()),pow1(len+1),pow2(len+1),h1(len+1),h2(len+1){
		pow1[0]=pow2[0]=1;
		rep(i,len){
			pow1[i+1]=pow1[i]*base%mod1;
			pow2[i+1]=pow2[i]*base%mod2;
			h1[i+1]=(h1[i]*base+s[i])%mod1;
			h2[i+1]=(h2[i]*base+s[i])%mod2;
		}
	}
	template<class T>
	rolling_hash(const vector<T>& a):len(a.size()),pow1(len+1),pow2(len+1),h1(len+1),h2(len+1){
		pow1[0]=pow2[0]=1;
		rep(i,len){
			pow1[i+1]=pow1[i]*base%mod1;
			pow2[i+1]=pow2[i]*base%mod2;
			h1[i+1]=(h1[i]*base+a[i])%mod1;
			h2[i+1]=(h2[i]*base+a[i])%mod2;
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
	template<class T>
	static hash_type get_hash(const vector<T>& a){
		long long res1=0,res2=0;
		rep(i,a.size()){
			res1=(res1*base+a[i])%mod1;
			res2=(res2*base+a[i])%mod2;
		}
		return {res1,res2};
	}
};

int main(){
	string s; cin>>s;
	int n=s.length();

	string t=s;
	reverse(t.begin(),t.end());

	rolling_hash R1(s),R2(t);

	vector dp(3,vector<lint>(n+1));
	for(int i=1;i<=n;i++){
		if(R1.get_hash(0,i)==R2.get_hash(n-i,n)) dp[0][i]=1;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(R1.get_hash(j,i)==R2.get_hash(n-i,n-j)) dp[1][i]+=dp[0][j];
		}
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<i;j++){
			dp[2][i]+=dp[1][j];
		}
	}

	lint ans=0;
	rep(i,n) if(R1.get_hash(i,n)==R2.get_hash(0,n-i)) ans+=dp[2][i];
	cout<<ans<<'\n';

	return 0;
}
