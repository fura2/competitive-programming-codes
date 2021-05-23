#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<pair<char,int>> run_length_encoding(const string& s){
	vector<pair<char,int>> res;
	int n=s.length(),pre=0;
	rep(i,n) if(i==n-1 || s[i]!=s[i+1]) res.emplace_back(s[i],i-pre+1), pre=i+1;
	return res;
}

int main(){
	int h,w,d; cin>>h>>w>>d;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	int ans=0;
	rep(i,h){
		for(auto p:run_length_encoding(B[i])){
			if(p.first=='.' && p.second>=d) ans+=p.second-d+1;
		}
	}
	rep(j,w){
		string t;
		rep(i,h) t+=B[i][j];
		for(auto p:run_length_encoding(t)){
			if(p.first=='.' && p.second>=d) ans+=p.second-d+1;
		}
	}
	cout<<ans<<'\n';

	return 0;
}
