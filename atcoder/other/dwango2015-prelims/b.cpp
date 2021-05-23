#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

vector<pair<char,int>> run_length_encoding(const string& s){
	vector<pair<char,int>> res;
	int n=s.length(),pre=0;
	rep(i,n) if(i==n-1 || s[i]!=s[i+1]) res.emplace_back(s[i],i-pre+1), pre=i+1;
	return res;
}

int main(){
	string s; cin>>s;
	int n=s.length();

	rep(i,n) if(i%2==1) {
		if     (s[i]=='2') s[i]='5';
		else if(s[i]=='5') s[i]='2';
	}

	lint ans=0;
	int pos=0;
	for(auto [c,len]:run_length_encoding(s)){
		if(c=='2' || c=='5'){
			lint t=len;
			if     (c=='2' && pos%2==1) t--;
			else if(c=='5' && pos%2==0) t--;
			ans+=t/2*(t/2+1)/2;
		}
		pos+=len;
	}
	printf("%lld\n",ans);

	return 0;
}
