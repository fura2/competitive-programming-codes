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
	string s1,s2; cin>>s1>>s2;

	int ans=0;
	for(auto p:run_length_encoding(s1+s2)) if(p.first=='o') ans=max(ans,p.second);
	printf("%d\n",ans);

	return 0;
}
