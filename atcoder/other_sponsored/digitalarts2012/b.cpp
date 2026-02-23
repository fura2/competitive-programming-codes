#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	if(s=="a" || s==string(20,'z')){
		cout<<"NO\n";
		return 0;
	}

	if(count(s.begin(),s.end(),s[0])==s.length()){
		if(s[0]=='a'){
			s.pop_back();
			s.back()++;
		}
		else if(s[0]=='z' || s.length()==1){
			s.back()--;
			s+='a';
		}
		else{
			s[0]++;
			s.back()--;
		}
	}
	else{
		int mx=0,mn=0;
		rep(i,s.length()){
			if(s[i]>s[mx]) mx=i;
			if(s[i]<s[mn]) mn=i;
		}
		swap(s[mx],s[mn]);
	}
	cout<<s<<'\n';

	return 0;
}
