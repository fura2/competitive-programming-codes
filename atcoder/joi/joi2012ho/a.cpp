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
	string s; cin>>s;

	int ans=0;
	auto RLE=run_length_encoding(s);
	for(int i=1;i+1<RLE.size();i++){
		if(RLE[i-1].first=='J' && RLE[i].first=='O' && RLE[i+1].first=='I'
		&& RLE[i-1].second>=RLE[i].second && RLE[i].second<=RLE[i+1].second){
			ans=max(ans,RLE[i].second);
		}
	}
	cout<<ans<<'\n';

	return 0;
}
