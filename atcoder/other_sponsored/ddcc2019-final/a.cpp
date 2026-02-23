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
	int n;
	string s; cin>>n>>s;

	double ans=0;
	int mx=0;
	for(auto [c,l]:run_length_encoding(s)){
		if(c=='-'){
			ans+=l;
		}
		else{
			rep(k,l) ans+=1.0/(k+2);
			mx=max(mx,l);
		}
	}
	ans+=1.0/(mx+2)-1;
	printf("%.9f\n",ans);

	return 0;
}
