#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool check(string s){
	if(s.length()>5) return false;
	rep(i,s.length()) if(!isdigit(s[i])) return false;
	if(s.length()>1 && s[0]=='0') return false;
	return stoi(s)<=12345;
}

int main(){
	string a,b; cin>>a>>b;
	puts(check(a)&&check(b)?"OK":"NG");
	return 0;
}
