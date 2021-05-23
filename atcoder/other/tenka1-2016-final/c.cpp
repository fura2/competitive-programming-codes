#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<int N,int OFFSET>
class trie{
	struct node{
		vector<int> accept;
		int nxt[N];
		node():accept(){
			fill(nxt,nxt+N,-1);
		}
	};
	vector<node> V;
public:
	trie():V(1){}
	void add(const string& s,int id){
		int len=s.length(),pos=0;
		rep(i,len){
			if(V[pos].nxt[s[i]-OFFSET]==-1){
				V[pos].nxt[s[i]-OFFSET]=V.size();
				V.emplace_back();
			}
			pos=V[pos].nxt[s[i]-OFFSET];
		}
		V[pos].accept.emplace_back(id);
	}
	vector<int> find_prefixes(const char* s)const{ // s の prefix に一致するパターン全体を求める
		auto res=V[0].accept;
		int pos=0;
		for(int i=0;s[i];i++){
			if(V[pos].nxt[s[i]-OFFSET]==-1){
				break;
			}
			pos=V[pos].nxt[s[i]-OFFSET];
			res.insert(res.end(),V[pos].accept.begin(),V[pos].accept.end());
		}
		return res;
	}
};

int main(){
	string s;
	int n; cin>>s>>n;
	trie<26,'a'> T;
	vector<string> pttn(n);
	rep(i,n){
		cin>>pttn[i];
		T.add(pttn[i],i);
	}
	vector<int> w(n);
	rep(i,n) cin>>w[i];

	int len=s.length();
	vector<int> dp(len+1);
	dp[0]=0;
	rep(i,len){
		for(auto id:T.find_prefixes(s.c_str()+i)){
			dp[i+pttn[id].length()]=max(dp[i+pttn[id].length()],dp[i]+w[id]);
		}
		dp[i+1]=max(dp[i+1],dp[i]);
	}
	printf("%d\n",*max_element(dp.begin(),dp.end()));

	return 0;
}
