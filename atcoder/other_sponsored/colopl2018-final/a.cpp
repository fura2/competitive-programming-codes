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
	int n;
	string s; cin>>n>>s;
	lint len=s.length();

	auto rle=run_length_encoding(s);

	if(rle.size()==1){
		if(s[0]=='A'){
			printf("%lld\n",(n*len)*(n*len+1)/2);
		}
		else{
			puts("0");
		}
		return 0;
	}

	vector<lint> a;
	for(auto p:rle) if(p.first=='A') a.emplace_back(p.second);

	lint ans=0;
	if(s[0]=='B' || s[len-1]=='B'){
		rep(i,a.size()) ans+=a[i]*(a[i]+1)/2;
		ans*=n;
	}
	else{
		for(int i=1;i<a.size()-1;i++) ans+=a[i]*(a[i]+1)/2;
		ans*=n;
		ans+=a[0]*(a[0]+1)/2;
		ans+=a.back()*(a.back()+1)/2;
		ans+=(n-1)*(a[0]+a.back())*(a[0]+a.back()+1)/2;
	}
	printf("%lld\n",ans);

	return 0;
}
