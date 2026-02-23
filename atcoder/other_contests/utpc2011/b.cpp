#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	int ans=0;
	rep(i,n/2){
		bool ok=false;
		if(s[i]=='i' && s[n-i-1]=='i') ok=true;
		if(s[i]=='w' && s[n-i-1]=='w') ok=true;
		if(s[i]=='(' && s[n-i-1]==')') ok=true;
		if(s[i]==')' && s[n-i-1]=='(') ok=true;
		if(!ok) ans++;
	}
	if(n%2==1 && s[n/2]!='i' && s[n/2]!='w') ans++;
	printf("%d\n",ans);

	return 0;
}
