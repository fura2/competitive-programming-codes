#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

inline int popcount(int x){
	x=((x>>1)&0x55555555)+(x&0x55555555);
	x=((x>>2)&0x33333333)+(x&0x33333333);
	x=((x>>4)+x)&0x0f0f0f0f;
	x+=(x>>8);
	x+=(x>>16);
	return x&0x3f;
}

string s;
vector<int> D;

// D を使って作れる, n と同じ桁数かつ n 以下の最大の整数を求める
lint dfs1(int i,bool smaller,lint cur){
	if(i==s.length()) return cur;

	lint res=-INF;
	if(smaller){
		res=max(res,dfs1(i+1,true,10*cur+D.back()));
	}
	else{
		int d=s[i]-'0';
		for(int j=D.size()-1;j>=0;j--) if(D[j]<=d) {
			res=max(res,dfs1(i+1,D[j]<d,10*cur+D[j]));
			if(D[j]<d) break;
		}
	}
	return res;
}

// D を使って作れる, n と同じ桁数かつ n 以上の最小の整数を求める
lint dfs2(int i,bool larger,lint cur){
	if(i==s.length()) return cur;

	lint res=INF;
	if(larger){
		res=min(res,dfs2(i+1,true,10*cur+D[0]));
	}
	else{
		int d=s[i]-'0';
		rep(j,D.size()) if(D[j]>=d) {
			res=min(res,dfs2(i+1,D[j]>d,10*cur+D[j]));
			if(D[j]>d) break;
		}
	}
	return res;
}

int main(){
	lint n;
	int k; cin>>n>>k;

	s=to_string(n);

	lint ans=INF;
	// n と同じ桁数
	rep(S,1<<10) if(popcount(S)==k) {
		D.clear();
		rep(d,10) if(S>>d&1) D.emplace_back(d);

		ans=min(ans,n-dfs1(0,false,0));
		ans=min(ans,dfs2(0,false,0)-n);
	}

	// n より小さい桁数
	lint nine=0;
	while(nine<=n) ans=min(ans,n-nine), nine=10*nine+9;

	// n より大きい桁数
	if(k==1){
		lint one=0;
		while(one<n) one=10*one+1;
		ans=min(ans,one-n);
	}
	else{
		lint ten=1;
		while(ten<n) ten=10*ten;
		ans=min(ans,ten-n);
	}

	cout<<ans<<'\n';

	return 0;
}
