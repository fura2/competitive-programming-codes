#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	vector<string> t;
	rep(i,s.length()){
		string a;
		if(isalnum(s[i])){
			a+=s[i];
		}
		else{
			a+=s[i]; i++;
			a+=s[i]; i++;
			a+=s[i];
		}
		if(!t.empty() || a!="ｗ") t.emplace_back(a);
	}

	int ans=0,pre=0;
	rep(i,t.size()+1) if(i==t.size() || t[i]!="ｗ") {
		ans=max(ans,i-pre);
		pre=i+1;
	}
	if(ans==0) return 0;

	pre=0;
	rep(i,t.size()+1) if(i==t.size() || t[i]!="ｗ") {
		if(pre>0 && i-pre==ans){
			int j;
			for(j=pre-1;j>=0;j--) if(t[j]=="ｗ") break;
			j++;
			for(;j<pre;j++) cout<<t[j];
			cout<<'\n';
		}
		pre=i+1;
	}

	return 0;
}
