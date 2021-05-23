#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	int d=0;
	rep(i,n) d+=s[i]-'0';

	string ans;
	while(d>0){
		ans+='0'+min(d,9);
		d-=min(d,9);
	}
	reverse(ans.begin(),ans.end());

	if(ans==s){
		if(ans[0]=='9' || ans.length()==1){
			ans=string("1")+char(ans[0]-1)+ans.substr(1);
		}
		else{
			ans[0]++;
			ans[1]--;
		}
	}

	cout<<ans<<'\n';

	return 0;
}
