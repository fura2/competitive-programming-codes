#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<string> dfs(int n){
	if(n==1) return {"AB"};

	vector<string> res;
	for(string s:dfs(n-1)){
		string t1,t2;
		for(char c:s){
			if(c=='A') t1+="AA", t2+="AB";
			else       t1+="BB", t2+="BA";
		}
		res.emplace_back(t1);
		res.emplace_back(t2);
	}

	string s;
	rep(i,1<<n-1) s+="AB";
	res.emplace_back(s);

	return res;
}

int main(){
	int n; cin>>n;

	auto ans=dfs(n);
	cout<<ans.size()<<'\n';
	for(string s:ans) cout<<s<<'\n';

	return 0;
}
