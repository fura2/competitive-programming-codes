#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s;
	int k; cin>>s>>k;
	int n=s.length();

	rep(i,n){
		if(s[i]!='a' && k>=26-(s[i]-'a')){
			k-=26-(s[i]-'a');
			s[i]='a';
		}
	}
	s[n-1]='a'+(s[n-1]-'a'+k)%26;

	cout<<s<<'\n';

	return 0;
}
