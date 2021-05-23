#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool ispali(string s){
	int n=s.length();
	rep(i,n) if(s[i]!=s[n-i-1]) return false;
	return true;
}

int main(){
	string s; cin>>s;
	int n=s.length();

	rep(i,n){
		string t=s.substr(0,i);
		reverse(t.begin(),t.end());
		if(ispali(s+t)){
			cout<<i<<endl;
			break;
		}
	}

	return 0;
}
