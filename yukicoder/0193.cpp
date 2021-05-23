#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

lint f(string s){
	lint res=0,num=0;
	char op='+';
	rep(i,s.length()+1){
		if(i==s.length() || !isdigit(s[i])){
			if(op=='+') res+=num;
			else        res-=num;
			num=0;
			if(i==s.length()) break;
		}

		if(isdigit(s[i])){
			num=10*num+(s[i]-'0');
		}
		else{
			op=s[i];
		}
	}
	return res;
}

int main(){
	string s; cin>>s;
	int n=s.length();
	s+=s;

	lint ans=-INF;
	rep(i,n) if(isdigit(s[i]) && isdigit(s[i+1])) {
		ans=max(ans,f(s.substr(i+1,n)));
	}
	cout<<ans<<'\n';

	return 0;
}
