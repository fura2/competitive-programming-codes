#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

string f(string s){
	lint x=0;
	for(char c:s) x=x*8+(c-'0');

	string t;
	do{
		t+=(x%9)+'0';
		x/=9;
	}while(x>0);
	reverse(t.begin(),t.end());
	return t;
}

string g(string s){
	for(char& c:s) if(c=='8') c='5';
	return s;
}

int main(){
	string s;
	int k; cin>>s>>k;

	rep(i,k){
		s=g(f(s));
	}
	cout<<s<<'\n';

	return 0;
}
