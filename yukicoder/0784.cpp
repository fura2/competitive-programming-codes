#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	reverse(s.begin(),s.end());
	string t;
	rep(i,s.length()){
		t+=s[i];
		if(i+1<s.length() && i%3==2) t+=',';
	}
	reverse(t.begin(),t.end());
	cout<<t<<'\n';
	return 0;
}
