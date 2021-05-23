#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

string dfs(string s,string t){
	if(s.empty() || t.empty()) return "";

	auto find_root=[&](string s)->pair<int,int>{
		int cnt=0;
		rep(i,s.length()){
			if(s[i]=='('){
				cnt++;
			}
			else if(s[i]==')'){
				cnt--;
				if(cnt==0){
					assert(s[i+1]=='[');
					int l=i+1,r=i+1;
					while(s[r]!=']') r++;
					return {l,r+1};
				}
			}
		}
		assert(0);
	};

	auto r1=find_root(s);
	auto r2=find_root(t);
	int num1=stoi(s.substr(r1.first+1,r1.second-r1.first-2));
	int num2=stoi(t.substr(r2.first+1,r2.second-r2.first-2));
	string chl1=s.substr(1,r1.first-2);
	string chr1=t.substr(1,r2.first-2);
	string chl2=s.substr(r1.second+1,s.length()-r1.second-2);
	string chr2=t.substr(r2.second+1,t.length()-r2.second-2);
	return "("+dfs(chl1,chr1)+")["+to_string(num1+num2)+"]("+dfs(chl2,chr2)+")";
}

int main(){
	string s,t; cin>>s>>t;
	cout<<dfs(s,t)<<'\n';
	return 0;
}
