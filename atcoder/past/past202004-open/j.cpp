#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

string calc(string s){
	int n=s.length();
	int pos=-1;
	rep(i,n){
		if(s[i]=='(') pos=i;
		if(s[i]==')'){
			string t=calc(s.substr(pos+1,i-pos-1));
			string r=t;
			reverse(r.begin(),r.end());
			return calc(s.substr(0,pos)+t+r+s.substr(i+1));
		}
	}
	return s;
}

int main(){
	string s; cin>>s;
	cout<<calc(s)<<'\n';
	return 0;
}
