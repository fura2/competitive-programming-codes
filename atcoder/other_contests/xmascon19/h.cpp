#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

vector<lint> prime_factors(lint a){
	vector<lint> res;
	if(a%2==0){
		do a/=2; while(a%2==0);
		res.emplace_back(2);
	}
	for(lint p=3;p*p<=a;p+=2) if(a%p==0) {
		do a/=p; while(a%p==0);
		res.emplace_back(p);
	}
	if(a>1) res.emplace_back(a);
	sort(res.begin(),res.end());
	return res;
}

bool solve1(const string& s){
	int n=s.length();
	vector<int> P;
	rep(i,n) if(s[i]=='.') P.emplace_back(i);
	if(P.size()<2) return true;

	for(auto p:prime_factors(P[1]-P[0])) if(p!=2) {
		bool ok=true;
		rep(i,P.size()) if((P[i]-P[0])%p!=0) ok=false;
		if(ok) return true;
	}
	return false;
}

bool solve2(const string& s){
	int n=s.length();
	vector<int> P;
	rep(i,n) if(s[i]=='.') P.emplace_back(i);
	if(P.size()<3) return true;

	auto check=[=](int a,int i0){
		for(auto p:prime_factors(a)) if(p!=2) {
			string t=s;
			for(int i=i0;i<n;i+=p) t[i]='#';
			if(solve1(t)) return true;
		}
		return false;
	};
	return check(P[1]-P[0],P[0]) || check(P[2]-P[0],P[0]) || check(P[2]-P[1],P[1]);
}

int solve(const string& s){
	if(count(s.begin(),s.end(),'.')==0) return 0;
	else if(solve1(s)) return 1;
	else if(solve2(s)) return 2;
	else               return 3;
}

int main(){
	int h,w; cin>>h>>w;

	int ans=0;
	rep(i,h){
		string s; cin>>s;
		ans+=solve(s);
	}
	cout<<ans<<'\n';

	return 0;
}
