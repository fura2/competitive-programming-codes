#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k;
	string s; cin>>n>>k>>s; k--;
	for(int i=k;i<n;i++){
		if(isupper(s[i])) s[i]=tolower(s[i]);
		else              s[i]=toupper(s[i]);
	}
	cout<<s<<'\n';
	return 0;
}
