#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	int ans=0;
	rep(S,1<<n){
		string t;
		rep(i,n) if(S>>i&1) t+=s[i];
		int m=t.length();

		if(t.find("iwi")!=string::npos){
			bool ok=true;
			rep(i,m/2){
				bool ok2=false;
				if(t[i]=='i' && t[m-i-1]=='i') ok2=true;
				if(t[i]=='w' && t[m-i-1]=='w') ok2=true;
				if(t[i]=='(' && t[m-i-1]==')') ok2=true;
				if(t[i]==')' && t[m-i-1]=='(') ok2=true;
				if(t[i]=='{' && t[m-i-1]=='}') ok2=true;
				if(t[i]=='}' && t[m-i-1]=='{') ok2=true;
				if(t[i]=='[' && t[m-i-1]==']') ok2=true;
				if(t[i]==']' && t[m-i-1]=='[') ok2=true;
				if(!ok2) ok=false;
			}
			if(m%2==1 && t[m/2]!='i' && t[m/2]!='w') ok=false;

			if(ok) ans=max(ans,m);
		}
	}
	printf("%d\n",ans);

	return 0;
}
