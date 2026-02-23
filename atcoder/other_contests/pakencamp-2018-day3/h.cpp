#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

string ten(int n){
	if(n==0) return "1";
	string res;
	rep(i,n) res+="2*5*";
	res.pop_back();
	return res;
}

int main(){
	string s; cin>>s;
	int n=s.length();

	string ans;
	rep(i,n){
		string t=ten(n-i-1);
		int d=s[i]-'0';
		if(d==0){
			continue;
		}
		else if(d==1){
			ans+=t;
		}
		else if(2<=d && d<=5){
			ans+=char('0'+d)+string("*")+t;
		}
		else if(d==6){
			ans+="2*3*"+t;
		}
		else if(d==7){
			ans+="3*5/2*"+t;
		}
		else if(d==8){
			ans+="2*4*"+t;
		}
		else{ // 9
			ans+="3*3*"+t;
		}
		ans+="+";
	}
	ans.pop_back();
	cout<<ans<<'\n';

	return 0;
}
