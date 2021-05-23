#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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
	int h,w; scanf("%d%d",&h,&w);
	char B[250][251];
	rep(i,h) scanf("%s",B[i]);

	vector<rolling_hash> H1(w),H2(w);
	rep(x,w){
		string s(h,'?');
		rep(y,h) s[y]=B[y][x];
		H1[x]=rolling_hash(s);
		reverse(s.begin(),s.end());
		H2[x]=rolling_hash(s);
	}

	int ans=0;
	rep(t,h) for(int b=t+2;b<=h;b++) {
		vector<int> v1(w),v2(w);
		map<rolling_hash::hash_type,int> f;
		rep(x,w){
			auto key=H1[x].get_hash(t,b);
			if(f.count(key)==0){ int val=f.size(); f[key]=val; }
			v1[x]=f[key];
			key=H2[x].get_hash(h-b,h-t);
			if(f.count(key)==0){ int val=f.size(); f[key]=val; }
			v2[x]=f[key];
		}
		reverse(v2.begin(),v2.end());

		rolling_hash K1(v1),K2(v2);
		// 偶数長
		for(int c=1;c<w;c++){
			int lo=0,hi=min(c,w-c)+1;
			while(hi-lo>1){
				int mi=(lo+hi)/2;
				if(K1.get_hash(c-mi,c+mi)==K2.get_hash(w-c-mi,w-c+mi)) lo=mi;
				else                                                   hi=mi;
			}
			ans+=lo;
		}
		// 奇数長
		rep(c,w) if(v1[c]==v2[w-c-1]) {
			int lo=0,hi=min(c,w-c-1)+1;
			while(hi-lo>1){
				int mi=(lo+hi)/2;
				if(K1.get_hash(c-mi,c+1+mi)==K2.get_hash(w-c-1-mi,w-c+mi)) lo=mi;
				else                                                       hi=mi;
			}
			ans+=lo;
		}
	}
	printf("%d\n",ans);

	return 0;
}
