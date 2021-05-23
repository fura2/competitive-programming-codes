#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	string ans;
	rep(i,s.length()){
		if(isalnum(s[i])){
			ans=s[i]+ans;
		}
		else{
			ans=s[i]+(s[i+1]+(s[i+2]+ans));
			i+=2;
		}
	}
	cout<<ans<<endl;
	return 0;
}
