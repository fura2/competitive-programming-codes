#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool dfs(string& s,const string& t,int cnt){
	if(cnt==3) return s==t;

	int n=s.length();
	rep(i,n) for(int j=i+1;j<n;j++) {
		swap(s[i],s[j]);
		if(dfs(s,t,cnt+1)) return true;
		swap(s[i],s[j]);
	}
	return false;
}

int main(){
	string s,t; cin>>s>>t;
	int n=s.length();

	{
		string s2,t2;
		rep(i,n) if(s[i]!=t[i]) {
			s2+=s[i];
			t2+=t[i];
		}
		if(s2.length()>6) return puts("NO"),0;

		bool dup=false;
		rep(i,n) for(int j=i+1;j<n;j++) if(s[i]==t[i] && s[j]==t[j] && s[i]==s[j]) dup=true;
		if(dup){
			s2+="@@";
			t2+="@@";
		}

		s=s2;
		t=t2;
	}

	puts(dfs(s,t,0)?"YES":"NO");

	return 0;
}
