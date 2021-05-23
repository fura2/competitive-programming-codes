#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int solve(string s){
	int n=s.length();
	int res=0;
	char op='+';
	rep(i,n){
		if(isdigit(s[i])){
			if(op=='+') res+=s[i]-'0';
			else        res-=s[i]-'0';
		}
		else if(s[i]=='+' || s[i]=='-'){
			op=s[i];
		}
		else{ // '(' or ')'
			int j=i+1;
			while(s[j]!=')') j++;
			if(op=='+') res+=solve(s.substr(i+1,j-i-1));
			else        res-=solve(s.substr(i+1,j-i-1));
			i=j;
		}
	}
	return res;
}

int main(){
	string s; cin>>s;
	cout<<solve(s)<<'\n';
	return 0;
}
