#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	rep(i,s.length()){
		s[i]-=(i+1)%26;
		if(s[i]<'A') s[i]+=26;
	}
	cout<<s<<'\n';
	return 0;
}
