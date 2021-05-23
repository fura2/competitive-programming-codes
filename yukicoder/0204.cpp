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
	int d;
	string s1,s2; cin>>d>>s1>>s2;

	string s=string(14,'x')+s1+s2+string(14,'x');

	int ans=0;
	rep(i,42){
		string t=s;
		rep(j,d){
			if(i+j>=42 || t[i+j]=='o') break;
			t[i+j]='o';
		}
		for(auto p:run_length_encoding(t)) if(p.first=='o') ans=max(ans,p.second);
	}
	cout<<ans<<'\n';

	return 0;
}
