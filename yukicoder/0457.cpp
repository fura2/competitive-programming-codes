#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int solve(string s){
	int n=s.length();
	int res=0;
	rep(i,n) if(s[i]=='(') {
		int phase=0;
		for(int j=i+1;j<n;j++){
			if(s[j]=='^'){
				if(phase<=1) phase++;
			}
			else if(s[j]=='*'){
				if(phase==2) phase=3;
			}
			else if(s[j]==')'){
				if(phase==3) res++;
			}
		}
	}
	return res;
}

int main(){
	string s; cin>>s;

	int ans1=solve(s);
	reverse(s.begin(),s.end());
	for(char& c:s){
		if     (c=='(') c=')';
		else if(c==')') c='(';
	}
	int ans2=solve(s);
	cout<<ans1<<' '<<ans2<<'\n';

	return 0;
}
